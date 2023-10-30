#pragma once

class Scene00 : public Scene
{
private:
	ObImage*	main1;
	ObImage*	main2;
	ObImage*	main3;

	ObImage*	anykey;

	float		anykey_time = 0.0f;

public:
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};

