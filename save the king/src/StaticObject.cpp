#include "StaticObject.h"

StaticObject::StaticObject(const sf::Vector2f& position, const sf::Vector2f& size, sf::Texture* texture)
	:GameObject(position, size, texture)
{
}

bool StaticObject::haveToDelete() const
{
	return m_delete;
}
