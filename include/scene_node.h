/*
 * scene_node.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef SCENE_NODE_H
#define SCENE_NODE_H


#include <SFML/Graphics.hpp>


class SceneNode :
	public sf::Transformable,
	public sf::Drawable,
	private sf::NonCopyable
{
	public:
		typedef std::unique_ptr<SceneNode> Ptr;

	public:
		SceneNode();
		void attachChild(Ptr child);
		Ptr detachChild(const SceneNode& node);
		void update(sf::Time dt);
		sf::Transform getWorldTransform() const;
		sf::Vector2f getWorldPosition() const;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void updateCurrent(sf::Time dt);
		void updateChildren(sf::Time dt);

	private:
		std::vector<Ptr> mChildren;
		SceneNode* mParent;
};

#endif /* SCENE_NODE_H */ 