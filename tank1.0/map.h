#pragma once
#include <stdio.h>
#include <windows.h>
// ������ʾ�����Ϸ�����ĸ߶ȺͿ��
enum {
	�� = 40,
	�� = 40
};


extern int g_map[��][��];

// ����˵����Ϸ�п��ܴ��ڵ����е���
enum {
	�յ� = 0,
	�߽� = 1,
	��� = 2,
	�ӵ� = 3,
	שǽ = 4,
	��ǽ = 5
};


void WriteChar(int High, int Wide, const char* Char, WORD wArr);

void DrawMap();
