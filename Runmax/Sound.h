#pragma once
#include "AssetManager.h"
#include "Libs.h"

class Sound
{
	// ������ �������� ��������
	std::vector<sf::Sound> m_sound;

public:

	// ������� ������ �������� ��������
	void create_sound(std::vector<std::string>& sound);
	// ����� ��������� ��������� ������� �������� �������������� � ���������� �������
	bool play(int index, bool loop);
	// ����� ���������� ��������� ������� �������� �������������� � ���������� �������
	void stop(int index);
	// ����� ���������� ���� �������� ��������
	void all_stop();
};

