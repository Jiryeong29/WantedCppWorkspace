#pragma once
// �Է� ó���� ���� ����ü.
struct KeyState
{
	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��.
	bool isKeyDown = false;

	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��.
	bool wasKeyDown = false;
};

// ���� Ŭ����
class Level;
class ENGINE_API Engine
{
public:

	Engine();
	virtual ~Engine();

	// ���� �����Լ�.
	void Run();

	// ���� �߰� �Լ�.
	void LoadLevel(Level* newLevel);


	// �Է� ���� �Լ�.
	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUP(int key);

	// ���� ���� �Լ�.
	void QuitGame();


	// �̱��� ��ü ���� �Լ�.
	static Engine& Get();

protected:
	void ProcessInput();			// �Է� ó��.
	void Update(float deltaTime);	// Tick().
	void Draw();					// Render();

	// ���� �������� Ű ���¸� �����ϴ� �Լ�.
	void SavePreviousKeyState();

private:

	// ������ �� ������ ����.
	bool quit;

	// Ű ���¸� �����ϴ� �迭.
	KeyState keyState[255];

	// �̱��� ������ ���� ���� ���� ����.
	static Engine* instance;

	// ���� ���� ����.
	Level* mainLevel;

};
