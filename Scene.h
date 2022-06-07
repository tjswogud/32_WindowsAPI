#pragma once

class Scene
{
public:
	// 생성자,소멸자에는 가상함수로 만들때, 0대신 default값을 준다.
	virtual ~Scene() = default;

	virtual void Update() = 0; // 매 프레임마다 정보를 갱신
	virtual void Render() = 0; // 매 프레임마다 화면을 갱신

private:

};
