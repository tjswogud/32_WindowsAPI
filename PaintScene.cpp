#include "Framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
	:color(BLACK), type(LINE), startPos({ 0, 0}), isClick(false)
{
	hPen[BLACK]  = CreatePen(PS_SOLID, 3, COLOR_BLACK);
	hPen[RED]    = CreatePen(PS_SOLID, 3, COLOR_RED  );
	hPen[GREEN]  = CreatePen(PS_SOLID, 3, COLOR_GREEN);
	hPen[BLUE]   = CreatePen(PS_SOLID, 3, COLOR_BLUE );

	hBrush[BLACK] = CreateSolidBrush(COLOR_BLACK);
	hBrush[RED]   = CreateSolidBrush(COLOR_RED  );
	hBrush[GREEN] = CreateSolidBrush(COLOR_GREEN);
	hBrush[BLUE]  = CreateSolidBrush(COLOR_BLUE );

}

PaintScene::~PaintScene()
{
	// 배열로 만들었기 떄문에 for문으로 한번에 삭제(delete)
	for (UINT i = 0; i < 4; i++)
	{
		DeleteObject(hPen  [i]);
		DeleteObject(hBrush[i]);
	}
}

void PaintScene::Update()
{
	SetState(); 

	// 여기에 들어왔다는건 버튼이 눌렸다는것
	if (GetAsyncKeyState(VK_LBUTTON))
	{
		// 계속 눌려있는건지 처음 눌린건지를 구분하기위해
		// LButtonDown을 누르는 동안에는 호출이 안되게끔
		if (!isClick)
			LButtonDown();
		else if (type == PEN)
				DrawPen();
	}
	else
	{
		// 안눌렸을떄
		// 계속 호출이 되면 안되고 딱 한번 땟을때만 기록해야 하기 떄문에
		if (isClick)
			LButtonUp();
	}
} 

void PaintScene::Render()
{
	Debug();

	DrawObjects();

	if (isClick)
		Preview();
}

void PaintScene::LButtonUp()
{
	isClick   = false;

	endPos = mousePos; // 끝나는 지점

	Data data;
	data.type     = this->type;
	data.color    = this->color;
	data.startPos = this->startPos;
	data.endPos   = this->endPos;

	objects.push_back(data);

}

void PaintScene::LButtonDown()
{
	isClick   = true;

	startPos = mousePos; // 버튼을 눌렀을때가 시작점이니까

}

void PaintScene::SetState()
{
	if (GetAsyncKeyState('1'))
		color = BLACK;
	if (GetAsyncKeyState('2'))
		color = RED;
	if (GetAsyncKeyState('3'))
		color = GREEN;
	if (GetAsyncKeyState('4'))
		color = BLUE;

	if (GetAsyncKeyState(VK_F1))
		type = PEN;
	if (GetAsyncKeyState(VK_F2))
		type = LINE;
	if (GetAsyncKeyState(VK_F3))
		type = RECT;
	if (GetAsyncKeyState(VK_F4))
		type = ELLIPSE;
}

void PaintScene::DrawPen()
{
	SelectObject(hdc, hPen[color]);
	SelectObject(hdc, hBrush[color]);

	endPos = mousePos;

	MoveToEx(hdc, startPos.x, startPos.y, nullptr);
	LineTo(hdc, endPos.x, endPos.y);

	// 시작할떄마다 endPos를 새로 잡아줘서 이어서 그릴수 있게
	startPos = endPos;

}

void PaintScene::DrawObjects()
{
	for (Data data : objects)
	{
		SelectObject(hdc,   hPen[data.color]);
		SelectObject(hdc, hBrush[data.color]);

		// data 타입에 따라 그려지는게 달라져야한다
		switch (type)
		{
		case PaintScene::LINE:
			MoveToEx(hdc, data.startPos.x, data.startPos.y, nullptr);
			LineTo(hdc, data.endPos.x, data.endPos.y);
			break;
		case PaintScene::RECT:
			Rectangle(hdc, data.startPos.x, data.startPos.y, data.endPos.x, data.endPos.y);
			break;
		case PaintScene::ELLIPSE:
			Ellipse(hdc, data.startPos.x, data.startPos.y, data.endPos.x, data.endPos.y);
			break;
		default:
			break;
		}
	}
}

void PaintScene::Preview() // 단순히 미리보기만 구현
{
	SelectObject(hdc,   hPen[color]);
	SelectObject(hdc, hBrush[color]);

	switch (type)
	{
	case PaintScene::LINE:
		MoveToEx(hdc, startPos.x, startPos.y, nullptr);
		LineTo(hdc, mousePos.x, mousePos.y);
		break;
	case PaintScene::RECT:
		Rectangle(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	case PaintScene::ELLIPSE:
		Ellipse(hdc, startPos.x, startPos.y, mousePos.x, mousePos.y);
		break;
	default:
		break;
	}
}

void PaintScene::Debug()
{
	wstring str;

	// string로는 글자끼리 더 하는게 가능하다 
	str = L"MousePos : " + to_wstring(mousePos.x) + L", " + to_wstring(mousePos.y);
	TextOut(hdc, 0, 0, str.c_str(), str.size());

	str = L"StartPos : " + to_wstring(startPos.x) + L", " + to_wstring(startPos.y);
	TextOut(hdc, 0, 20, str.c_str(), str.size());

	str = L"  EndPos : " + to_wstring(endPos.x) + L", " + to_wstring(endPos.y);
	TextOut(hdc, 0, 40, str.c_str(), str.size());
}
