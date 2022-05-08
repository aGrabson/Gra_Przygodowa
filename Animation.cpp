#include "Animation.h"
sf::Texture Animation::objectAnimation(std::map<std::string, sf::Texture>& textures, double dtTime,float oneFrameTime,std::string name,bool &lastFrame)
{

	sumaTime += dtTime;
	if (sumaTime >= oneFrameTime)
	{
		textureIndex++;
		if (textureIndex > (textures.size()))
		{
			textureIndex = 1;
			lastFrame = true;
		}
			
		sumaTime = 0;
	}
	return textures.find(name+std::to_string(textureIndex))->second;
}

Animation::Animation()
{
	sumaTime = 0;
	textureIndex = 1;
}
