#include "stdafx.h"

Yggdrasil::Yggdrasil()
{
	//Col
	boss_Col = new ObRect();
	boss_Col->scale = Vector2(250.0f, 250.0f);
	boss_Col->SetWorldPos(Vector2(-100.0f, -900.0f));
	boss_Col->visible = false;
	boss_Col->isFilled = false;
	//boss_Col->pivot = OFFSET_LT;
	boss_Col->collider = COLLIDER::RECT;

	for (int i = 0; i < 2; i++)
	{
		boss_Col_LR[i] = new ObRect();
		boss_Col_LR[i]->scale = Vector2(180.0f, 15.0f);
		//boss_Col_LR[i]->SetParentRT(*boss_Col);
		boss_Col_LR[i]->visible = false;
		boss_Col_LR[i]->isFilled = false;
		boss_Col_LR[i]->pivot = OFFSET_LT;
		boss_Col_LR[i]->collider = COLLIDER::RECT;
	}
	 
	boss_Col_LR[0]->SetLocalPos(Vector2(-345.0f, -315.0f));
	boss_Col_LR[1]->SetLocalPos(Vector2(60.0f, -238.0f));

	//얼굴
	face1 = new ObImage(L"bossface_top.png");
	face1->scale = Vector2(256.0f, 256.0f) * 2.0f;
	face1->SetParentRT(*boss_Col);
	face1->SetWorldPos(Vector2(-30.0f, 10.0f));
	face1->visible = true;

	face2 = new ObImage(L"bossface_top_p2.png");
	face2->scale = Vector2(256.0f, 256.0f) * 2.0f;
	face2->SetParentRT(*face1);
	face2->SetWorldPos(Vector2(-20.0f, 0.0f));
	face2->visible = false;

	face2_Die = new ObImage(L"bossface_top_end.png");
	face2_Die->scale = Vector2(256.0f, 256.0f) * 2.0f;
	face2_Die->SetParentRT(*face1);
	face2_Die->SetWorldPos(Vector2(-20.0f, 0.0f));
	face2_Die->visible = false;

	bossDie_Face = new ObImage(L"bossface_top_die.png");
	bossDie_Face->scale = Vector2(256.0f, 256.0f) * 2.0f;
	bossDie_Face->SetParentRT(*face1);
	bossDie_Face->SetWorldPos(Vector2(-20.0f, 0.0f));
	bossDie_Face->visible = false;
	
	//몸
	body1 = new ObImage(L"bossbody.png");
	body1->scale = Vector2(512.0f, 512.0f) * 2.5f;
	//body1->SetParentRT(*boss_Col);
	body1->SetWorldPos(Vector2(-100.0f, -900.0f));
	body1->visible = true;

	body2 = new ObImage(L"bossbody_p2.png");
	body2->scale = Vector2(512.0f, 512.0f) * 2.5f;
	body2->SetParentRT(*body1);
	body2->SetWorldPos(Vector2(-100.0f, -150.0f));
	body2->visible = false;

	bossDie_Boddy = new ObImage(L"bossbody_end.png");
	bossDie_Boddy->scale = Vector2(512.0f, 512.0f) * 2.5f;
	bossDie_Boddy->SetParentRT(*body1);
	bossDie_Boddy->SetWorldPos(Vector2());
	bossDie_Boddy->visible = false;

	//턱
	bottom1 = new ObImage(L"bossface_bottom.png");
	bottom1->scale = Vector2(128.0f, 128.0f) * 2.0f;
	bottom1->SetParentRT(*boss_Col);
	bottom1->SetWorldPos(Vector2(0.0f, -110.0f));
	bottom1->visible = true;

	bottom2 = new ObImage(L"bossface_bottom_p2.png");
	bottom2->scale = Vector2(128.0f, 128.0f) * 2.0f;
	bottom2->SetParentRT(*face1);
	bottom2->SetWorldPos(Vector2());
	bottom2->visible = false;

	bossDie_Bottom = new ObImage(L"bossface_bottom_end.png");
	bossDie_Bottom->scale = Vector2(128.0f, 128.0f) * 2.0f;
	bossDie_Bottom->SetParentRT(*face1);
	bossDie_Bottom->SetWorldPos(Vector2(20.0f, -130.0f));
	bossDie_Bottom->visible = false;

	//손
	hand_Col = new ObRect();
	hand_Col->scale = Vector2(3072.0f / 12.0f, 256.0f);
	//hand_Col->SetParentRT(*boss_Col);
	hand_Col->SetWorldPos(Vector2(-500.0f, -700.0f));
	hand_Col->pivot = OFFSET_B;
	hand_Col->visible = false;
	hand_Col->isFilled = false;
	hand_Col->collider = COLLIDER::RECT;

	hand_Col_Reverse = new ObRect();
	hand_Col_Reverse->scale = Vector2(3072.0f / 12.0f, 256.0f);
	//hand_Col_Reverse->SetParentRT(*boss_Col);
	hand_Col_Reverse->SetWorldPos(Vector2(300.0f, -700.0f));
	hand_Col_Reverse->pivot = OFFSET_B;
	hand_Col_Reverse->visible = false;
	hand_Col_Reverse->isFilled = false;
	hand_Col_Reverse->collider = COLLIDER::RECT;

	hand_Idle = new ObImage(L"bosshand.png");
	hand_Idle->scale = Vector2(3072.0f / 12.0f, 256.0f) * 2.0f;
	hand_Idle->SetParentRT(*hand_Col);
	hand_Idle->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Idle->maxFrame.x = 12;
	hand_Idle->pivot = OFFSET_B;
	hand_Idle->visible = false;
	hand_Idle->ChangeAnim(ANIMSTATE::LOOP, 0.45f);

	hand_Idle_Reverse = new ObImage(L"bosshand.png");
	hand_Idle_Reverse->scale = Vector2(3072.0f / 12.0f, 256.0f) * 2.0f;
	hand_Idle_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Idle_Reverse->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Idle_Reverse->maxFrame.x = 12;
	hand_Idle_Reverse->pivot = OFFSET_B;
	hand_Idle_Reverse->visible = false;
	hand_Idle_Reverse->reverseLR = true;
	hand_Idle_Reverse->ChangeAnim(ANIMSTATE::LOOP, 0.45f);

	hand_Idle2 = new ObImage(L"bosshand_p2.png");
	hand_Idle2->scale = Vector2(2048.0f / 8.0f, 128.0f);
	hand_Idle2->SetParentRT(*hand_Col);
	hand_Idle2->pivot = OFFSET_B;
	hand_Idle2->SetWorldPos(Vector2());
	hand_Idle2->maxFrame.x = 8;
	hand_Idle2->visible = false;
	hand_Idle2->ChangeAnim(ANIMSTATE::LOOP, 0.45f);
			 
	hand_Idle2_Reverse = new ObImage(L"bosshand_p2.png");
	hand_Idle2_Reverse->scale = Vector2(2048.0f / 8.0f, 128.0f);
	hand_Idle2_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Idle2_Reverse->pivot = OFFSET_B;
	hand_Idle2_Reverse->SetWorldPos(Vector2());
	hand_Idle2_Reverse->maxFrame.x = 8;
	hand_Idle2_Reverse->visible = false;
	hand_Idle2_Reverse->reverseLR = true;
	hand_Idle2_Reverse->ChangeAnim(ANIMSTATE::LOOP, 0.45f);

	hand_Bomb = new ObImage(L"bosshands_end.png");
	hand_Bomb->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Bomb->SetParentRT(*hand_Col);
	hand_Bomb->pivot = OFFSET_B;
	hand_Bomb->SetWorldPos(Vector2(0.0f, -170.0f));
	hand_Bomb->visible = false;

	hand_Bomb_Reverse = new ObImage(L"bosshands_end.png");
	hand_Bomb_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Bomb_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Bomb_Reverse->SetWorldPos(Vector2(0.0f, -170.0f));
	hand_Bomb_Reverse->pivot = OFFSET_B;
	hand_Bomb_Reverse->visible = false;
	hand_Bomb_Reverse->reverseLR = true;

	hand_Bomb2 = new ObImage(L"bosshand_bomb.png");
	hand_Bomb2->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Bomb2->SetParentRT(*hand_Col);
	hand_Bomb2->pivot = OFFSET_B;
	hand_Bomb2->SetWorldPos(Vector2(0.0f, -170.0f));
	hand_Bomb2->visible = false;

	hand_Bomb2_Reverse = new ObImage(L"bosshand_bomb.png");
	hand_Bomb2_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Bomb2_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Bomb2_Reverse->SetWorldPos(Vector2(0.0f, -170.0f));
	hand_Bomb2_Reverse->pivot = OFFSET_B;
	hand_Bomb2_Reverse->visible = false;
	hand_Bomb2_Reverse->reverseLR = true;

	hand_Slam = new ObImage(L"bosshand_left_slam.png");
	hand_Slam->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Slam->SetParentRT(*hand_Col);
	hand_Slam->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Slam->pivot = OFFSET_B;
	hand_Slam->visible = false;
	hand_Slam->collider = COLLIDER::RECT;
	hand_Slam->colOnOff = false;

	hand_Slam_Reverse = new ObImage(L"bosshand_right_slam.png");
	hand_Slam_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Slam_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Slam_Reverse->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Slam_Reverse->pivot = OFFSET_B;
	hand_Slam_Reverse->visible = false;
	hand_Slam_Reverse->reverseLR = true;
	hand_Slam_Reverse->collider = COLLIDER::RECT;
	hand_Slam->colOnOff = false;

	hand_Slam_Start = new ObImage(L"bomb_Start.png");
	hand_Slam_Start->scale = Vector2(362.0f / 2.0f * 0.7f, 104.0f) * 2.5f;
	hand_Slam_Start->SetParentRT(*hand_Col);
	hand_Slam_Start->SetWorldPos(Vector2(0.0f, -50.0f));
	hand_Slam_Start->pivot = OFFSET_B;
	hand_Slam_Start->maxFrame = Int2(2, 1);
	hand_Slam_Start->ChangeAnim(ANIMSTATE::LOOP, 0.6f);
	hand_Slam_Start->visible = false;
	hand_Slam_Start->colOnOff = false;

	hand_Slam_Reverse_Start = new ObImage(L"bomb_Start.png");
	hand_Slam_Reverse_Start->scale = Vector2(362.0f / 2.0f * 0.7f, 104.0f) * 2.5f;
	hand_Slam_Reverse_Start->SetParentRT(*hand_Col_Reverse);
	hand_Slam_Reverse_Start->SetWorldPos(Vector2(0.0f, -50.0f));
	hand_Slam_Reverse_Start->pivot = OFFSET_B;
	hand_Slam_Reverse_Start->maxFrame = Int2(2,1);
	hand_Slam_Reverse_Start->ChangeAnim(ANIMSTATE::LOOP, 0.6f);
	hand_Slam_Reverse_Start->visible = false;
	hand_Slam_Reverse_Start->reverseLR = true;
	hand_Slam->colOnOff = false;

	hand_Slam2 = new ObImage(L"bosshand_slam_p2.png");
	hand_Slam2->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Slam2->SetParentRT(*hand_Col);
	hand_Slam2->SetWorldPos(Vector2());
	hand_Slam2->pivot = OFFSET_B;
	hand_Slam2->visible = false;
			 
	hand_Slam2_Reverse = new ObImage(L"bosshand_slam_p2.png");
	hand_Slam2_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Slam2_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Slam2_Reverse->SetWorldPos(Vector2());
	hand_Slam2_Reverse->pivot = OFFSET_B;
	hand_Slam2_Reverse->visible = false;
	hand_Slam2_Reverse->reverseLR = true;

	hand_Sweep = new ObImage(L"bosshand_sweep.png");
	hand_Sweep->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Sweep->SetParentRT(*hand_Col);
	hand_Sweep->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Sweep->pivot = OFFSET_B;
	hand_Sweep->visible = false;

	hand_Sweep_Reverse = new ObImage(L"bosshand_sweep.png");
	hand_Sweep_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Sweep_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Sweep_Reverse->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Sweep_Reverse->pivot = OFFSET_B;
	hand_Sweep_Reverse->visible = false;
	hand_Sweep_Reverse->reverseLR = true;

	hand_Sweep2 = new ObImage(L"bosshand_sweep_p2.png");
	hand_Sweep2->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Sweep2->SetParentRT(*hand_Col);
	hand_Sweep2->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Sweep2->pivot = OFFSET_B;
	hand_Sweep2->visible = false;
			  
	hand_Sweep2_Reverse = new ObImage(L"bosshand_sweep_p2.png");
	hand_Sweep2_Reverse->scale = Vector2(256.0f, 256.0f) * 2.0f;
	hand_Sweep2_Reverse->SetParentRT(*hand_Col_Reverse);
	hand_Sweep2_Reverse->SetWorldPos(Vector2(0.0f, -150.0f));
	hand_Sweep2_Reverse->pivot = OFFSET_B;
	hand_Sweep2_Reverse->visible = false;
	hand_Sweep2_Reverse->reverseLR = true;

	//나무 바닥
	boss_TreeGround = new ObImage(L"Boss_TreeGround.bmp.");
	boss_TreeGround->scale = Vector2(3600.0f / 9.0f, 200.0f / 2.0f) * 2.0f;
	//boss_TreeGround->SetParentRT(*boss_Col);
	boss_TreeGround->SetWorldPos(Vector2(-650.0f, -400.0f));
	boss_TreeGround->maxFrame.x = 9;
	boss_TreeGround->maxFrame.y = 2;
	boss_TreeGround->visible = true;
	boss_TreeGround->reverseLR = false;
	boss_TreeGround->ChangeAnim(ANIMSTATE::ONCE, 0.15f);

	boss_TreeGround2 = new ObImage(L"Boss_TreeGround.bmp");
	boss_TreeGround2->scale = Vector2(3600.0f / 9.0f, 200.0f / 2.0f) * 2.0f;
	//boss_TreeGround2->SetParentRT(*boss_Col);
	boss_TreeGround2->SetWorldPos(Vector2(450.0f, -400.0f));
	boss_TreeGround2->visible = true;
	boss_TreeGround2->reverseLR = true;
	boss_TreeGround2->maxFrame.x = 9;
	boss_TreeGround2->maxFrame.y = 2;
	boss_TreeGround2->ChangeAnim(ANIMSTATE::ONCE, 0.15f);

	//HP
	bossHpBar = new ObImage(L"BosshpBar_0.bmp");
	bossHpBar->scale = Vector2(798.0f, 112.0f);
	//bossHpBar->SetParentRT(*boss_Col);
	bossHpBar->SetWorldPos(Vector2(-400.0f, 400.0f));
	bossHpBar->pivot = OFFSET_L;
	bossHpBar->visible = false;
	bossHpBar->space = SPACE::SCREEN;

	bossHp = new ObImage(L"Bosshp.bmp");
	bossHp->scale = Vector2(798.0f, 112.0f);
	bossHp->SetParentRT(*bossHpBar);
	//bossHp->SetWorldPos(Vector2(0.0f, 0.0f));
	bossHp->pivot = OFFSET_L;
	bossHp->visible = false;
	bossHp->space = SPACE::SCREEN;

	//BALL
	ball_Energy = new ObImage(L"Energy.png");
	ball_Energy->scale = Vector2(6656.0f / 52.0f, 128.0f) * 2.0f;
	ball_Energy->SetParentRT(*boss_Col);
	ball_Energy->SetWorldPos(Vector2(0.0f, 100.0f));
	ball_Energy->maxFrame = Int2(52,1);
	ball_Energy->ChangeAnim(ANIMSTATE::ONCE, 0.05f);
	ball_Energy->visible = false;

	for (int i = 0; i < 8; i++)
	{
		ball_Col[i] = new ObCircle();
		ball_Col[i]->scale = Vector2(500.0f / 10.0f, 50.0f);
		ball_Col[i]->SetParentRT(*ball_Energy);
		ball_Col[i]->visible = false;
		ball_Col[i]->isFilled = false;
		ball_Col[i]->collider = COLLIDER::CIRCLE;

		ball_Shooting[i] = new ObImage(L"grimSoul.bmp");
		ball_Shooting[i]->scale = Vector2(500.0f / 10.0f, 50.0f) * 2.0f;
		ball_Shooting[i]->SetParentRT(*ball_Col[i]);
		ball_Shooting[i]->maxFrame = Int2(10, 1);
		ball_Shooting[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		ball_Shooting[i]->visible = false;
	}
	
	ball_BigCol = new ObCircle();
	ball_BigCol->scale = Vector2(200.0f, 200.0f);
	ball_BigCol->SetParentRT(*ball_Energy);
	ball_BigCol->visible = false;
	ball_BigCol->isFilled = false;
	ball_BigCol->collider = COLLIDER::CIRCLE;

	ball_Big = new ObImage(L"ElderEntP2_EnergyCorps_Spark.png");
	ball_Big->scale = Vector2(5376.0f / 24.0f, 224.0f) * 2.0f;
	ball_Big->SetParentRT(*ball_BigCol);
	ball_Big->maxFrame = Int2(24, 1);
	ball_Big->ChangeAnim(ANIMSTATE::LOOP, 0.05f);
	ball_Big->visible = false;

	groggy_Emerge = new ObImage(L"ElderEntP2_EnergyCorps_Projectile_Emerge.png");
	groggy_Emerge->scale = Vector2(4800.0f / 25.0f, 192.0f) * 3.0f;
	groggy_Emerge->SetParentRT(*ball_BigCol);
	groggy_Emerge->SetLocalPosY(-100.0f);
	groggy_Emerge->maxFrame = Int2(25, 1);
	groggy_Emerge->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
	groggy_Emerge->visible = false;

	groggy_Effect = new ObImage(L"ElderEnt_Die_Impact.png");
	groggy_Effect->scale = Vector2(7488.0f / 39.0f * 1.2f, 192.0f) * 6.0f;
	groggy_Effect->SetParentT(*boss_Col);
	groggy_Effect->SetLocalPosY(100.0f);
	groggy_Effect->maxFrame = Int2(39, 1);
	groggy_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
	groggy_Effect->visible = false;

	die_Effect = new ObImage(L"ElderEnt_Die_Impact.png");
	die_Effect->scale = Vector2(7488.0f / 39.0f * 1.2f, 192.0f) * 6.0f;
	die_Effect->SetParentT(*boss_Col);
	die_Effect->SetLocalPosY(100.0f);
	die_Effect->maxFrame = Int2(39, 1);
	die_Effect->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
	die_Effect->visible = false;

	start_Effect1 = new ObImage(L"ElderEnt_Die_Impact.png");
	start_Effect1->scale = Vector2(7488.0f / 39.0f * 1.2f, 192.0f) * 3.0f;
	start_Effect1->SetWorldPos(Vector2(-500.0f, -450.0f));
	start_Effect1->maxFrame = Int2(39, 1);
	start_Effect1->ChangeAnim(ANIMSTATE::ONCE, 0.06f);
	start_Effect1->visible = false;

	start_Effect2 = new ObImage(L"ElderEnt_Die_Impact.png");
	start_Effect2->scale = Vector2(7488.0f / 39.0f * 1.2f, 192.0f) * 3.0f;;
	start_Effect2->SetWorldPos(Vector2(300.0f, -450.0f));
	start_Effect2->maxFrame = Int2(39, 1);
	start_Effect2->ChangeAnim(ANIMSTATE::ONCE, 0.06f);
	start_Effect2->visible = false;

	ball_Ex = new ObImage(L"ball_Ex.png");
	ball_Ex->scale = Vector2(15614.0f / 37.0f, 422.0f) * 1.7f;
	ball_Ex->SetParentRT(*ball_Big);
	ball_Ex->maxFrame = Int2(37, 1);
	ball_Ex->ChangeAnim(ANIMSTATE::ONCE, 0.06f);
	ball_Ex->visible = false;

	//처음 땅찍 1,2
	SOUND->AddSound("ElderEnt_Impact [Legacy].wav", "Bomb", false);
	SOUND->AddSound("ElderEnt_Impact [Legacy].wav", "Bomb2", false);

	//Start Roar
	SOUND->AddSound("ElderEnt_Roar.wav", "Roar", false);
	SOUND->AddSound("ElderEnt_Normalize [Legacy].wav", "Nomalize", false);
	//그로기
	SOUND->AddSound("ElderEnt_Groggy_Intro [Legacy].wav", "groggy", false);
	SOUND->AddSound("Enemy_Stomp.wav", "groggy_Stomp", false);
	//Ball
	SOUND->AddSound("ElderEnt_EnergyBomb_Ready.wav", "EnergyReady", false);
	SOUND->AddSound("ElderEnt_EnergyBomb_Fire.wav", "EnergyFire", false);

	//Groggy Recovery
	SOUND->AddSound("ElderEnt_Groggy_Recovery.wav", "GroggyRecovery", false);

	//Sweeping
	SOUND->AddSound("ElderEnt_Sweeping.wav", "Sweeping", false);
	SOUND->AddSound("ElderEnt_Sweeping_Roar.wav", "Sweeping_Start", false);

	//S L A M
	SOUND->AddSound("ElderEnt_FistSlam_Roar [Legacy].wav", "First_Slam", false);
	SOUND->AddSound("Enemy_Stomp.wav", "Slam_Stomp", false);

	bossPattern = BossPattern::START;
}

Yggdrasil::~Yggdrasil()
{
	SafeDelete(boss_Col);

	for (int i = 0; i < 2; i++)
	{
		SafeDelete(boss_Col_LR[i]);
	}
	SafeDelete(face1);
	SafeDelete(face2);
	SafeDelete(face2_Die);
	SafeDelete(bossDie_Face);

	SafeDelete(body1);
	SafeDelete(body2);
	SafeDelete(bossDie_Boddy);

	SafeDelete(bottom1);
	SafeDelete(bottom2);
	SafeDelete(bossDie_Bottom);

	SafeDelete(hand_Idle);
	SafeDelete(hand_Idle_Reverse);
	SafeDelete(hand_Idle2);
	SafeDelete(hand_Idle2_Reverse);

	SafeDelete(hand_Bomb);
	SafeDelete(hand_Bomb_Reverse);
	SafeDelete(hand_Bomb2);
	SafeDelete(hand_Bomb2_Reverse);

	SafeDelete(hand_Slam);
	SafeDelete(hand_Slam_Reverse);
	SafeDelete(hand_Slam2);
	SafeDelete(hand_Slam2_Reverse);
		
	SafeDelete(hand_Sweep);
	SafeDelete(hand_Sweep_Reverse);
	SafeDelete(hand_Sweep2);
	SafeDelete(hand_Sweep2_Reverse);

	SafeDelete(boss_TreeGround);
	SafeDelete(boss_TreeGround2);

	SafeDelete(bossHpBar);
	SafeDelete(bossHp);

	SafeDelete(ball_Energy);

	for (int i = 0; i < 8; i++)
	{
		SafeDelete(ball_Shooting[i])
		SafeDelete(ball_Col[i])
	}

	SafeDelete(ball_Big);
	SafeDelete(ball_BigCol);

	SafeDelete(groggy_Emerge);
	SafeDelete(groggy_Effect);
	SafeDelete(die_Effect);
	SafeDelete(start_Effect1);
	SafeDelete(start_Effect2);
}

void Yggdrasil::Update()
{
	switch (bossPattern)
	{
	case BossPattern::START:
		Start();
		break;
	case BossPattern::IDLE:
		Idle();
		break;
	case BossPattern::SLAM:
		Slam();
		break;
	case BossPattern::SWEEP:
		Sweep();
		break;
	case BossPattern::BALL:
		Ball();
		break;
	case BossPattern::GROGGY:
		Groggy();
		break;
	case BossPattern::DIE:
		Die();
		break;
	}

	if (5.0f < start_time && start_time < 6.5f)
	{
		bossHpBar->visible = true;
		bossHp->visible = true;

		bossHpBar->MoveWorldPos(UP * 80.0f * sinf(start_time / 0.8f * DIV2PI) * DELTA);
	}

	//Ball_Shoot
	for (int i = 0; i < 8; i++)
	{
		if (ball_Shooting[i]->visible)
		{
			ball_BigCol->visible = false;
			ball_Big->visible = true;

			Vector2 ball1 = UP + Vector2(-3.0f, 0.0f);
			Vector2 ball2 = UP + Vector2(-0.5f, 0.0f);
			Vector2 ball3 = UP + Vector2(0.5f, 0.0f);
			Vector2 ball4 = UP + Vector2(3.0f, 0.0f);
			Vector2 ball5 = DOWN + Vector2(-3.0f, 0.0f);
			Vector2 ball6 = DOWN + Vector2(-0.5f, 0.0f);
			Vector2 ball7 = DOWN + Vector2(0.5f, 0.0f);
			Vector2 ball8 = DOWN + Vector2(3.0f, 0.0f);

			ball1.Normalize();
			ball2.Normalize();
			ball3.Normalize();
			ball4.Normalize();
			ball5.Normalize();
			ball6.Normalize();
			ball7.Normalize();
			ball8.Normalize();

			ball_Col[0]->MoveWorldPos(ball1 * 80.0f * DELTA);
			ball_Col[1]->MoveWorldPos(ball2 * 80.0f * DELTA);
			ball_Col[2]->MoveWorldPos(ball3 * 80.0f * DELTA);
			ball_Col[3]->MoveWorldPos(ball4 * 80.0f * DELTA);
			ball_Col[4]->MoveWorldPos(ball5 * 80.0f * DELTA);
			ball_Col[5]->MoveWorldPos(ball6 * 80.0f * DELTA);
			ball_Col[6]->MoveWorldPos(ball7 * 80.0f * DELTA);
			ball_Col[7]->MoveWorldPos(ball8 * 80.0f * DELTA);
		}
	}
	
	boss_Col->Update();

	for (int i = 0; i < 2; i++)
	{
		boss_Col_LR[i]->Update();
	}

	face1->Update();
	face2->Update();
	face2_Die->Update();
	bossDie_Face->Update();

	body1->Update();
	body2->Update();
	bossDie_Boddy->Update();

	bottom1->Update();
	bottom2->Update();
	bossDie_Bottom->Update();

	hand_Col->Update();
	hand_Col_Reverse->Update();

	hand_Idle->Update();
	hand_Idle_Reverse->Update();
	hand_Idle2->Update();
	hand_Idle2_Reverse->Update();

	hand_Bomb->Update();
	hand_Bomb_Reverse->Update();
	hand_Bomb2->Update();
	hand_Bomb2_Reverse->Update();

	hand_Slam->Update();
	hand_Slam_Reverse->Update();
	hand_Slam2->Update();
	hand_Slam2_Reverse->Update();

	hand_Sweep->Update();
	hand_Sweep_Reverse->Update();
	hand_Sweep2->Update();
	hand_Sweep2_Reverse->Update();

	boss_TreeGround->Update();
	boss_TreeGround2->Update();

	bossHpBar->Update();
	bossHp->Update();
	ball_Energy->Update();

	for (int i = 0; i < 8; i++)
	{
		ball_Shooting[i]->Update();
		ball_Col[i]->Update();
	}

	ball_Big->Update();
	ball_BigCol->Update();
	groggy_Emerge->Update();
	groggy_Effect->Update();
	die_Effect->Update();

	start_Effect1->Update();
	start_Effect2->Update();

	hand_Slam_Start->Update();
	hand_Slam_Reverse_Start->Update();

	ball_Ex->Update();
}

void Yggdrasil::Render()
{
	body1->Render();
	body2->Render();
	bossDie_Boddy->Render();

	face1->Render();
	face2->Render();
	face2_Die->Render();
	bossDie_Face->Render();

	bottom1->Render();
	bottom2->Render();
	bossDie_Bottom->Render();

	//hand_Idle->Render();
	//hand_Idle_Reverse->Render();
	hand_Idle2->Render();
	hand_Idle2_Reverse->Render();

	hand_Bomb->Render();
	hand_Bomb_Reverse->Render();
	hand_Bomb2->Render();
	hand_Bomb2_Reverse->Render();

	//hand_Slam->Render();
	//hand_Slam_Reverse->Render();
	hand_Slam2->Render();
	hand_Slam2_Reverse->Render();

	//hand_Sweep->Render();
	//hand_Sweep_Reverse->Render();
	hand_Sweep2->Render();
	hand_Sweep2_Reverse->Render();

	boss_TreeGround->Render();
	boss_TreeGround2->Render();

	//bossHpBar->Render();
	//bossHp->Render();
	hand_Col->Render();
	hand_Col_Reverse->Render();

	boss_Col->Render();

	for (int i = 0; i < 2; i++)
	{
		boss_Col_LR[i]->Render();
	}

	ball_Energy->Render();

	for (int i = 0; i < 8; i++)
	{
		ball_Shooting[i]->Render();
		ball_Col[i]->Render();
	}

	ball_Big->Render();
	ball_BigCol->Render();
	groggy_Emerge->Render();
	groggy_Effect->Render();
	die_Effect->Render();

	start_Effect1->Render();
	start_Effect2->Render();
	hand_Slam_Start->Render();
	hand_Slam_Reverse_Start->Render();

	ball_Ex->Render();
}

void Yggdrasil::Start()
{
	start_time += DELTA;

	Boss_AllInvisible();
	Pase1_Idle();

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Bomb->visible = false;
	hand_Bomb_Reverse->visible = false;

	hand_Slam_Start->visible = true;
	hand_Slam_Reverse_Start->visible = true;

	if (hand_Slam_Start->frame.x >= 1.0f)
	{
		hand_Slam_Start->ChangeAnim(ANIMSTATE::STOP, 0.0f);
	}

	//Bomb 올리기
	if (start_time < 0.4f)
	{
		hand_Col->MoveWorldPos(UP * 500.0f * DELTA);
	}

	if (hand_Slam_Reverse_Start->frame.x >= 1.0f)
	{
		hand_Slam_Reverse_Start->ChangeAnim(ANIMSTATE::STOP, 0.0f);
	}

	if (0.8f < start_time && start_time < 1.2f)
	{
		hand_Col_Reverse->MoveWorldPos(UP * 500.0f * DELTA);
	}

	//Bomb 내리기
	if (0.6f < start_time && start_time < 0.8f)
	{
		hand_Col->MoveWorldPos(DOWN * 50.0f * DELTA);
		start_Effect1->visible = true;
		SOUND->Play("Bomb");
	}

	if (1.4f < start_time && start_time < 1.8f)
	{
		hand_Col_Reverse->MoveWorldPos(DOWN * 50.0f * DELTA);
		start_Effect2->visible = true;
		SOUND->Play("Bomb2");
	}

	if (1.4f < start_time && start_time < 2.5f)
	{
		boss_Col->MoveWorldPos(UP * 700.0f * DELTA);
		body1->MoveWorldPos(UP * 600.0f * DELTA);
	}

	if (2.4f < start_time && start_time < 2.8f)
	{
		boss_Col->MoveWorldPos(DOWN * 300.0f * DELTA);
		start_Effect1->visible = false;
		start_Effect2->visible = false;
	}

	//턱아래로
	if (2.6f < start_time && start_time < 3.1f)
	{
		SOUND->Play("Nomalize");
		SOUND->Play("Roar");
		bottom1->MoveWorldPos(DOWN * 45.0f * DELTA);
	}

	if (4.6f < start_time && start_time < 5.1f)
	{
		boss_Col->MoveWorldPos(UP * 200.0f * DELTA);
		body1->MoveWorldPos(UP * 200.0f * DELTA);
	}

	if (5.1f < start_time && start_time < 5.6f)
	{
		bottom1->MoveWorldPos(UP * 45.0f * DELTA);
	}

	//cout << start_time << endl;

	//Start -> Idle
	if (start_time > 6.5f)
	{
		bossPattern = BossPattern::IDLE;
	}


}

void Yggdrasil::Idle()
{
	boss_Col_LR[0]->colOnOff = true;
	boss_Col_LR[1]->colOnOff = true;

	//Idle 머리 움직이게 하기
	Boss_AllInvisible();
	Pase1_Idle();
	HeadMove_Idle();

	groggy_Effect->frame.x = 0.0f;

	hand_Slam->colOnOff = false;
	hand_Slam_Reverse->colOnOff = false;

	hand_Slam_Start->visible = false;
	hand_Slam_Reverse_Start->visible = false;

	hand_Idle->colOnOff = false;
	hand_Idle_Reverse->colOnOff = false;

	hand_Col->colOnOff = false;
	hand_Col_Reverse->colOnOff = false;

	for (int i = 0; i < 8; i++)
	{
		ball_Col[i]->visible = false;
		ball_Shooting[i]->visible = false;
	}

	boss_Col->SetWorldPos(Vector2(-100.0f, -150.0f));
	body1->SetWorldPos(Vector2(-100.0f, -150.0f));
	hand_Col->SetWorldPos(Vector2(-500.0f, -500.0f));
	hand_Col_Reverse->SetWorldPos(Vector2(300.0f, -500.0f));
	bottom1->SetLocalPos(Vector2(0.0f, -110.0f));

	boss_Col->rotation = 0.0f;
	bottom1->rotation = 0.0f;
	body1->rotation = 0.0f;

	start_time = 0.0f;

	//Idle -> Slam
	slam_time = 0.0f;
	slam_time2 = 0.0f;

	//Idle -> Sweep
	sweep = 2;
	sweep_time = 0.0f;
	sweep_time2 = 0.0f;

	//Idle -> Ball
	ball = 3;

	ball_time = 0.0f;
	groggy_time = 0.0f;

	ball_Shoot = false;
	groggy_Check = false;

	groggy_Effect->visible = false;
	die_Effect->visible = false;

	groggy_Emerge->frame.x = 0;
	groggy_Emerge->visible = false;
}

void Yggdrasil::Slam()
{
	boss_Col_LR[0]->colOnOff = false;
	boss_Col_LR[1]->colOnOff = false;

	//Slam
	Boss_AllInvisible();
	Pase1_Idle();
	//HeadMove_Idle();

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Slam->visible = true;
	hand_Slam_Reverse->visible = true;

	hand_Col->colOnOff = true;
	hand_Col_Reverse->colOnOff = true;

	slam_time += DELTA;
	slam_time2 += DELTA;

	//cout << slam_time << endl;

	//손들어
	

	//손 들면서 머리 위로 올라가기
	if (slam_time < 1.5f)
	{
		boss_Col->MoveWorldPos(UP * 80.0f * sinf(slam_time / 0.8f * DIV2PI) * DELTA);
		boss_Col->MoveWorldPos(RIGHT * 100.0f * sinf(slam_time / 0.05f * DIV2PI) * DELTA);
		bottom1->MoveWorldPos(UP * 25.0f * DELTA);
	}

	if (1.5f < slam_time && slam_time < 2.2f)
	{
		boss_Col->MoveWorldPos(DOWN * 250.0f * DELTA);
		bottom1->MoveWorldPos(DOWN * 35.0f * DELTA);
	}

	//찍기
	//Scene04에서

	//Slam -> Idle
}

void Yggdrasil::Sweep()
{
	//Sweep
	Boss_AllInvisible();
	Pase1_Idle();
	HeadMove_Idle();

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Sweep->visible = true;
	hand_Sweep_Reverse->visible = true;

	sweep_time += DELTA;
	sweep_time2 += DELTA;

	//1초동안 손 양쪽으로 이동

	//Sweep -> Idle
}

void Yggdrasil::Ball()
{
	//Ball -> Idle
	Boss_AllInvisible();
	Pase1_Idle();
	//HeadMove_Idle();
	//cout << ball << endl;

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Bomb->visible = true;
	hand_Bomb_Reverse->visible = true;

	ball_time += DELTA;
	ball_Energy->visible = true;

	//cout << ball_time << endl;

	//부르르
	if (10.0f <= ball_Energy->frame.x && ball_Energy->frame.x <= 50.0f)
	{
		//cout << "11" << endl;
		boss_Col->MoveWorldPos(RIGHT * 80.0f * sinf(ball_time / 0.03f * DIV2PI) * DELTA);
	}
	
	//2.4 ~ 2.7초 사이에 위로 올라가기
	if (2.4f < ball_time && ball_time < 2.7f)
	{
		boss_Col->MoveWorldPos(UP * 800.0f * DELTA);
	}

	//2.8~ 3.0초 턱 아래로 내리면서 Shoot
	if (2.8f < ball_time && ball_time <= 3.4f)
	{
		bottom1->MoveWorldPos(DOWN * 150.0f * cosf(ball_time / 0.66f * DIV2PI) * DELTA);
		ball_Shoot = true;
	}

	//ball_Shoot이 true면 공날리기 3번해야함
	if (ball_Shoot)
	{
		bottom1->MoveWorldPos(UP * 20.0f * DELTA);
		ball_Energy->visible = false;

		for (int i = 0; i < 8; i++)
		{
			ball_Col[i]->visible = false;
			ball_Shooting[i]->visible = true;
		}
	}

}

void Yggdrasil::Groggy()
{
	boss_Col_LR[0]->colOnOff = false;
	boss_Col_LR[1]->colOnOff = false;

	Boss_AllInvisible();
	Pase1_Idle();

	groggy_Effect->rotation = 0.0f;
	die_Effect->rotation = 0.0f;

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Bomb->visible = true;
	hand_Bomb_Reverse->visible = true;

	ball_Big->visible = false;
	ball_BigCol->visible = false;

	groggy_time += DELTA;
	//cout << groggy_time << endl;

	//GoGo
	if (groggy_time < 0.3f)
	{
		SOUND->Play("groggy");
		groggy_Emerge->visible = true;
		groggy_Emerge->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		groggy_Check = true;
		bottom1->MoveWorldPos(DOWN * 150.0f * DELTA);
	}

	//Groggy Sound
	if (1.95f < groggy_time && groggy_time < 2.12f)
	{
		SOUND->Play("groggy_Stomp");
	}
	
}

void Yggdrasil::Die()
{
	boss_Col_LR[0]->colOnOff = false;
	boss_Col_LR[1]->colOnOff = false;

	Boss_AllInvisible();
	face2_Die->visible = true;
	bossDie_Boddy->visible = true;
	bossDie_Bottom->visible = true;

	die_time += DELTA;

	hand_Idle->visible = false;
	hand_Idle_Reverse->visible = false;

	hand_Bomb->visible = true;
	hand_Bomb_Reverse->visible = true;

	groggy_Emerge->ChangeAnim(ANIMSTATE::LOOP, 0.05f);

	if (groggy_Emerge->frame.x >= 23)
	{
		groggy_Emerge->visible = false;
	}

	die_Check = true;

	if (die_time < 0.3f)
	{
		SOUND->Play("groggy");
		groggy_Emerge->visible = true;
		hand_Col->MoveWorldPos(DOWN * 50.0f * DELTA);
		hand_Col_Reverse->MoveWorldPos(DOWN * 50.0f * DELTA);
	}

	if (1.95f < die_time && die_time < 2.12f)
	{
		SOUND->Play("groggy_Stomp");
	}


}

void Yggdrasil::HeadMove_Idle()
{
	//cout << move_time << endl;

	move_time += DELTA;

	if (move_time <= 0.7f)
	{
		face1->MoveWorldPos(UP * 15.3f * DELTA);
		bottom1->MoveWorldPos(UP * 15.0f * cosf(move_time / 0.6f * DIV2PI) * DELTA);
	}

	else if(move_time > 0.7f)
	{
		face1->MoveWorldPos(DOWN * 15.0f * DELTA);
		bottom1->MoveWorldPos(DOWN * 15.0f * sinf(move_time / 0.666f * DIV2PI) * DELTA);
	}

	if (move_time > 1.4f)
	{
		move_time = 0.0f;
	}
	
}
