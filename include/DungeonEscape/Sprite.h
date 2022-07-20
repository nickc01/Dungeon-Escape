#pragma once
#include <SDL.h>
#include <tuple>
#include <memory>
#include <DungeonEscape/Vector2.h>
#include <DungeonEscape/Rect.h>

class Sprite
{
	std::shared_ptr<SDL_Texture> texture;

	SDL_Rect texture_rect;

public:
	Sprite(const char* file_path,Rect<int> textureRect);
	Sprite(const char* file_path);
	Sprite();

	Vector2f position{ 0.0f,0.0f };
	Vector2f scale{ 1.0f, 1.0f };
	Vector2f origin{ 0.5f,0.5f };
	double rotation;

	SDL_RendererFlip flipMode = SDL_RendererFlip::SDL_FLIP_NONE;

	RectF GetTextureRect() const;
	RectF GetLocalRect() const;
	RectF GetGlobalRect() const;

	Vector2i GetSize() const;

	void SetTextureRect(RectI rect);
	void SetTextureRect(SDL_Rect rect);

	Vector2f GetOriginPosOffset() const;

	void DrawSprite(SDL_Renderer* renderer) const;
	void DrawSpriteUI(SDL_Renderer* renderer) const;
};