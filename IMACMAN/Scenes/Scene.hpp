//
//  Scene.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 19/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Scene_h
#define Scene_h

#include "libraries.hpp"
#include "Core/GameObject.hpp"

class Scene
{
public:

	/**
	 Fast-forward method to instanciate, init and in the scene GameObj
	 */
	static void load();

	/**
	 Initialize the scene
	 */
	virtual void init() = 0;

	/**
	 Execute all the actions in the scene
	 */
	virtual void execute() = 0;

	/**
	 Render the scene on the screen
	 */
	virtual void render() = 0;

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	virtual ~Scene() {}

	/**
	 Enable the scene
	 */
	inline void enable()  { m_enable = true; };

	/**
	 Disable the scene
	 */
	inline void disable() { m_enable = false; };

	/**
	 Tell if the scene is enabled or not

	 @return True if enabled, false otherwise
	 */
	inline bool isEnabled() const { return m_enable; };

	/**
	 Return the unique ID of the scene

	 @return UUID
	 */
	inline boost::uuids::uuid getUUID() const { return m_sceneID; };

	/**
	 Scene constructor, generate the scene UUID
	 */
	Scene():m_sceneID(GameObj->getUUID()) {}

	/**
	 Comparison operator for the scenes
	 Two scenes are equals if they have the same UUID.

	 @return True if the scenes are the same
	 */
	bool operator == (Scene * scene)
	{
		return getUUID() == scene->getUUID();
	};

private:

	boost::uuids::uuid m_sceneID;

	bool m_enable = true;
};

#include "sceneTest001.hpp"
#include "sceneTest002.hpp"
#include "sceneConsole.hpp"


#endif /* Scene_h */
