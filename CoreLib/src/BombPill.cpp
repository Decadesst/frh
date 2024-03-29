#include "BombPill.h"

BombPill::BombPill(SpriteInfo* p_spriteInfo, Tile* p_tile, GameStats* p_gameStats, CollectableContainer* p_container, SoundInfo* p_onUseSound): Collectable(p_spriteInfo, p_gameStats, p_container)
{
	m_tile = p_tile;
	if (m_tile)
		m_tile->addPill(this);
	m_consumed = false;
	m_onUseSound = p_onUseSound;
}
BombPill::~BombPill()
{
}
void BombPill::update(float p_deltaTime, InputInfo p_inputInfo)
{
	Collectable::update(p_deltaTime,p_inputInfo); // call collectable generic update
}
void BombPill::consume()
{
	if (!m_consumed && m_gameStats->getItemSlot() == NULL)
	{
		m_consumed = true;
		m_tile = NULL;
		if (m_gameStats)
			m_gameStats->setItemSlot(this);
		if (m_spriteInfo)
			m_spriteInfo->visible = false;
		if (m_onUseSound)
			m_onUseSound->play = true;
	}
}
void BombPill::activate()
{
	//if (m_onUseSound)
		//m_onUseSound->play = true;
}