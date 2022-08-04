#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture)
: m_sprite(*texture)
{
	init(position, size);
}

GameObject::GameObject(sf::Texture* texture)
	: m_sprite(*texture)
{
}

void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void GameObject::move(sf::Vector2f toMove)
{
	m_sprite.move(toMove);
}

void GameObject::init(sf::Vector2f position, sf::Vector2f size)
{
	setSize(size);
	setPosition(position);
}

bool GameObject::checkCollision(const GameObject& other) const
{
	return getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

void GameObject::setColorGreen()
{
	m_sprite.setColor(sf::Color::Green);
}

void GameObject::setColorWhite()
{
	m_sprite.setColor(sf::Color::White);
}

void GameObject::setPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

void GameObject::setSize(sf::Vector2f size)
{
	m_sprite.setOrigin({ m_sprite.getGlobalBounds().width / 2 , m_sprite.getGlobalBounds().height / 2 });
	m_sprite.scale({size.x / m_sprite.getGlobalBounds().width, size.y / m_sprite.getGlobalBounds().height});
}
