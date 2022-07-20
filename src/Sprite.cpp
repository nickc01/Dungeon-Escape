#include <DungeonEscape/Sprite.h>
#include <DungeonEscape/Common.h>
#include <SDL_image.h>
#include <stdio.h>
#include <DungeonEscape/Math.h>

namespace 
{
    struct texture_deleter
    {
        void operator ()(SDL_Texture* p)
        {
            SDL_DestroyTexture(p);
        }
    };
}

Sprite::Sprite(const char* file_path)
{
	auto loaded_surface = IMG_Load(file_path);

    //Convert surface to screen format
    SDL_Surface* surface = SDL_ConvertSurface(loaded_surface, Common::MainWindowSurface->format, 0);
    if (surface == NULL)
    {
        printf("Unable to optimize image %s! SDL Error: %s\n", file_path, SDL_GetError());
    }

    texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(Common::MainWindowRenderer, surface), texture_deleter());

    texture_rect = loaded_surface->clip_rect;

    //Get rid of old loaded surface
    SDL_FreeSurface(loaded_surface);
    SDL_FreeSurface(surface);
}

Sprite::Sprite() {}

/*Sprite::Sprite(const Sprite& sprite)
{
    surface = sprite.surface;
    surface->refcount++;

    texture = sprite.texture;
}

Sprite::Sprite(Sprite&& sprite) {
    surface = std::move(sprite.surface);
    texture = std::move(sprite.texture);
}

Sprite& Sprite::operator=(const Sprite& other) {
    surface = other.surface;
    surface->refcount++;

    texture = other.texture;
}

Sprite& Sprite::operator=(Sprite&& other) {
    surface = std::move(other.surface);
    texture = std::move(other.texture);
}

Sprite::~Sprite() {
    if (surface != nullptr)
    {
        SDL_FreeSurface(surface);
    }
}*/

/*float Sprite::GetXPos() const
{
    return std::get<0>(position);
}
float Sprite::GetYPos() const
{
    return std::get<1>(position);
}

void Sprite::SetXPos(float x)
{
    std::get<0>(position) = x;
}

void Sprite::SetYPos(float y)
{
    std::get<1>(position) = y;
}

float Sprite::GetXScale() const
{
    return std::get<0>(scale);
}
float Sprite::GetYScale() const
{
    return std::get<1>(scale);
}

void Sprite::SetXScale(float x)
{
    std::get<0>(scale) = x;
}

void Sprite::SetYScale(float y)
{
    std::get<1>(scale) = y;
}*/

RectF Sprite::GetTextureRect() const
{
    return RectF(texture_rect.x,texture_rect.y,texture_rect.w,texture_rect.h);
}

RectF Sprite::GetLocalRect() const
{
    auto rect = GetTextureRect();
    rect.width *= scale.GetX();
    rect.height *= scale.GetY();
    return rect;
}

RectF Sprite::GetGlobalRect() const
{
    auto rect = GetLocalRect();
    auto originOffset = GetOriginPosOffset();
    rect.x = position.GetX() + originOffset.GetX();
    rect.y = position.GetY() + originOffset.GetY();
    return rect;
}

void Sprite::DrawSprite(SDL_Renderer* renderer) const {

    auto rect = GetGlobalRect();

    //rect.x -= Math::Lerp(0.0f, rect.width, origin.GetX());
    //rect.y -= Math::Lerp(0.0f, rect.height, origin.GetY());

    rect.x -= Common::CameraPosition.GetX();
    rect.y -= Common::CameraPosition.GetY();

    auto windowSize = Common::GetWindowDimensions();

    rect.x += windowSize.GetX() / 2;
    rect.y += windowSize.GetY() / 2;

    SDL_Rect render_rect;

    render_rect.x = rect.x;
    render_rect.y = rect.y;
    render_rect.w = rect.width;
    render_rect.h = rect.height;

    if (SDL_RenderCopyEx(renderer, texture.get(), nullptr, &render_rect, rotation, nullptr, flipMode) > 0)
    {
        printf("Failed to render sprite %s",SDL_GetError());
    }
}

Vector2f Sprite::GetOriginPosOffset() const
{
    auto rect = GetLocalRect();
    return Vector2f(-Math::Lerp(0.0f, rect.width, origin.GetX()), -Math::Lerp(0.0f, rect.height, origin.GetY()));
}