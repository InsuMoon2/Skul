#pragma once

class Scene0000 : public Scene
{
private:
	ObImage* black;

	//Text
	ObImage* text;
	ObImage* next;

	bool	text_Checking = false;

	float	text_Time = 0.0f;
	int		number = 0;

	bool	fadeOut;
	float	fadeIn;

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

