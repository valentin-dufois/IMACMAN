//
//  Scene.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 19/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Scene_h
#define Scene_h

#include "../main.hpp"

//Forward declarations
class Asset;

class Scene
{
public:

	/**
	 Initialize the scene
	 */
	virtual void init() = 0;

	/**
	 Execute all the actions in the scene
	 */
	virtual void execute() = 0;

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	virtual ~Scene() {};

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
	 Return all the assets of the scene

	 @return The assets in a vector
	 */
	inline std::vector<Asset *> getAssets() const { return m_assets; };

	/**
	 Return the unique ID of the scene

	 @return UUID
	 */
	inline boost::uuids::uuid getUUID() const { return m_sceneID; };

	/**
	 Scene constructor, generate the scene UUID
	 */
	Scene():m_sceneID(GameObj->getUUID()) {};

	bool operator == (Scene * scene)
	{
		return getUUID() == scene->getUUID();
	};

private:

	boost::uuids::uuid m_sceneID;

	bool m_enable;
	std::vector<Asset *> m_assets;
};


#endif /* Scene_h */
