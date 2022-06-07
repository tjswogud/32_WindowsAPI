#pragma once

class PaintScene : public Scene
{
	enum Color
	{
		BLACK,
		RED,
		GREEN,
		BLUE
	} color;

	enum Type
	{
		PEN,
		LINE,
		RECT,
		ELLIPSE
	} type;

	struct Data
	{
		Type type;
		Color color;

		Vector2 startPos;
		Vector2   endPos;
	};
public:
	PaintScene();
	~PaintScene();

	// 부모클래스에 순수가상함수를 가져온다
	virtual void Update() override;
	virtual void Render() override;

	void SetState();

	void LButtonUp();
	void LButtonDown();

	void DrawPen();
	void DrawObjects();

	void Preview();

	void Debug();

private:
	Vector2 startPos; // 마우스 클릭
	Vector2   endPos; // 클릭을 땐 상태

	HPEN	 hPen[4];
	HBRUSH hBrush[4];

	bool isClick;

	//Preview 미리보기 기능

	vector<Data> objects;
};

