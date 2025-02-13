#pragma once

//collision.h

#define CONIOEX
#include "common.h"


//プレイヤー　対　足場
//px, py フィールドにぶつかっているかを調べたい座標
//
bool	CollisionPlayerField(float px, float py);

//弾１つ　対　敵全部
// bullet=弾構造体ポインター
bool	CollisonBulletEnemy(OBJECT* bullet);





//衝突判定
//点と矩形
//
//Px,Py=点の座標
//Lx,Ly=矩形の左上の座標 
//Sx,Sy=矩形の横縦サイズ
//
bool	CollisionPointBox(float Px, float Py, float Lx, float Ly, float Sx, float Sy);

//矩形と矩形
//
//L1x,L1y=矩形１の左上座標
//S1x,S1y=矩形１の横縦サイズ
//L2x,L2y=矩形２の左上座標
//S2x,S2y=矩形２の横縦サイズ
//
bool	CollisionBoxBox(float L1x, float L1y, float S1x, float S1y,
						float L2x, float L2y, float S2x, float S2y);


/*

  R1x=L1x+S1x					R2x=L2x+S2x
  R1y=L1y+S1y                   R2y=L2y+S2y

  (L1x,L1y)                     (L2x,L2y)
     o---------                       o-------------------
	 |        |                       |                  |
	 |        |                       |                  |
	 |        |                       |                  |
	 ---------o                       |                  |
	       (R1x,R1y)                  |                  |
		                              |------------------o
									                 (R2x,R2y)

     当たっていない条件  
	 R1x < L2x         矩形１が矩形２の完全に左側にいる
	 L1x > R2x         矩形１が矩形２の完全に下側にいる＜＜＜右側にいるに修正！
	 L2y > R1y         矩形２が矩形１の完全に下側にいる
	 R2y < L1y         矩形２が矩形１の完全に上側にいる
	 どれか1つでも成立すれば当たらないと考える


	 
*/

//-------------------
//円と円（円と点）




