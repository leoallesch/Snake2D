#include "MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context)
{

}
MainMenu::~MainMenu()
{

}

void MainMenu::Init()
{
	m_context->m_assets->AddFont();
}

void MainMenu::ProcessInput()
{

}

void MainMenu::Update(sf::Time deltaTime)
{

}

void MainMenu::Draw()
{

}