#pragma once


class Application
{
public:
	Application();
	~Application();
	void Run();

private:
	void Load();
	void Unload(); //release all memory
	
	void Update();
	void Draw();

private:
	
};