/*
高さhと幅wがともに整数である長方形を整長方形と呼ぶ．
横長整長方形 (w　> h) の大小関係を次のように定める．
　・対角線の長さが短いほうが小さい．
　・対角線の長さが同じならば，高さの低いほうが小さい．
与えられた横長整長方形に対し，それより大きい最小の横長整長方形を求めるプログラムを作る。

まず最優先で探すものが、読み込んだ対角線と同じ長さ、読み込んだ高さより高い、
そして今までの最小値の高さより低いものなので一番最初に分岐させる。
その後、読み込んだ対角線よりは大きいが、最小値の対角線との長さが等しく最小値の高さよりも低い場合か、
最小値の対角線よりも小さい場合を探す。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define N 150

bool same_diagonal1(int d, int h, int i); /*読み込んだ対角線と同じ長さ、読み込んだ高さより高い、最小値の高さより低い、これを最優先に探す*/
bool same_diagonal2(int d, int h, int i);
bool large_diagonal(int d, int h, int i); /*読み込んだ対角線よりは大きく、最小値の対角線との長さが等しく最小値の高さよりも低い場合か、最小値の対角線よりも小さい場合*/
void set_value(int d, int i, int j);
void first_set_up(int h, int w);

static bool s_flag;
static int min_h, min_w, min_d, diagonal;

int main(){
int h, w, d, i, j;
	/*h=0,w=0が押されるまで読み込み続ける*/
	while(scanf("%d%d", &h, &w)){
		if(h == 0 && w == 0) break;
		else{
			first_set_up(h, w);
			/*150まで縦と横の辺同士の掛け算をしていく*/
			for(i = 1; i < N; i++){
				for(j = i+1; j <= N; j++){
					d = i*i + j*j;
					if(same_diagonal1(d, h, i)){
						s_flag = true;
						set_value(d, i, j);
					}else if(large_diagonal(d, h, i) && !s_flag){
						set_value(d, i, j);
						
					}
				}
			}
			printf("%d %d\n", min_h, min_w);
		}
	}
}
bool same_diagonal1(int d, int h, int i){
	if(d == diagonal && i > h){
		if((i < min_h && s_flag) || !s_flag) return true;
	}
	return false;
}
bool large_diagonal(int d, int h, int i){
	if(d > diagonal){
		if(same_diagonal2(d, h, i) || d < min_d) return true;
	}
	return false;
}
bool same_diagonal2(int d, int h, int i){
	if(d == min_d && i > h && i < min_h) return true;
	return false;
}
void set_value(int d, int i, int j){
	min_d = d;
	min_h = i;
	min_w = j;
}
void first_set_up(int h, int w){
	diagonal = h*h + w*w; //対角線の長さの2乗
	min_d = N*N;
	min_h = N+1;
	min_w = N+1;
	s_flag = false;
}


