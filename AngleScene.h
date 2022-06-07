#pragma once

class AngleScene : public Scene
{
public:
	AngleScene();
	~AngleScene();

	virtual void Update() override;
	virtual void Render() override;
private:
	Tank* tank;
};