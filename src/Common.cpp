#include <DungeonEscape/Common.h> //Contains many common game functions and variables
#include <string> //Contains std::string
#include <time.h> //Contains the time() function for getting the current time
#include <random> //Contains the rand() and srand() functions for creating random values
#include <DungeonEscape/Math.h> //Contains many commonly used math functions
#include <DungeonEscape/Direction.h> //Contains the Direction Enum for specifying the direction
#include <DungeonEscape/Graphics.h>
#include <smk/Sprite.hpp>
#include <smk/Input.hpp>

using namespace std; //Prevents me from having to type std everywhere
using namespace smk; //Prevents me from having to type sf everywhere

namespace
{
    //Create a sprite with the specified texture and origin point
    Sprite CreateSprite(const Texture& texture, Vector2f origin)
    {
        //Create the sprite with the set texture
        auto sprite = Sprite(texture);
        //Reset the sprite's position
        sprite.SetPosition({0,0});
        //Set the sprite's origin
        //sprite.SetOrigin(origin);
        sprite.SetCenter(std::get<0>(origin),std::get<1>(origin));
        //Return the sprite
        return sprite;
    }

    //Create a sprite with the specified texture
    Sprite CreateSprite(const Texture& texture)
    {
        return CreateSprite(texture, static_cast<Vector2f>(Vector2i(texture.width(), texture.height()) / 2));
    }

    //Create a sprite with the specified texture and origin
    Sprite CreateSprite(const ResourceTexture& texture, Vector2f origin)
    {
        return CreateSprite(texture.GetTexture(),origin);
    }
    //Create a sprite with the specified texture
    Sprite CreateSprite(const ResourceTexture& texture)
    {
        return CreateSprite(texture.GetTexture());
    }
}

namespace Common
{
    namespace Sprites
    {
        //A list of all common sprites used for both the rooms and the branches

        Sprite centerPiece1;
        Sprite centerPiece2;

        Sprite topJointPiece;
        Sprite bottomJointPiece;
        Sprite leftJointPiece;
        Sprite rightJointPiece;

        Sprite topLeftPiece;
        Sprite topRightPiece;
        Sprite bottomLeftPiece;
        Sprite bottomRightPiece;
        Sprite topPiece;
        Sprite bottomPiece;
        Sprite rightPiece;
        Sprite leftPiece;
    }

    namespace Textures
    {
        //A list of all common textures used for both the rooms and the branches
        //These are then used by the Common Sprites

        ResourceTexture centerPiece1{RES_CENTERPIECE1};
        ResourceTexture centerPiece2{RES_CENTERPIECE2};

        ResourceTexture topJointPiece{RES_TOPJOINT};
        ResourceTexture bottomJointPiece{RES_BOTTOMJOINT};
        ResourceTexture leftJointPiece{RES_LEFTJOINT};
        ResourceTexture rightJointPiece{RES_RIGHTJOINT};

        ResourceTexture topLeftPiece{RES_TOPLEFTPIECE};
        ResourceTexture topRightPiece{RES_TOPRIGHTPIECE};
        ResourceTexture bottomLeftPiece{RES_BOTTOMLEFTPIECE};
        ResourceTexture bottomRightPiece{RES_BOTTOMRIGHTPIECE};
        ResourceTexture topPiece{RES_TOPPIECE};
        ResourceTexture bottomPiece{RES_BOTTOMPIECE};
        ResourceTexture rightPiece{RES_RIGHTPIECE};
        ResourceTexture leftPiece{RES_LEFTPIECE};
    }

    //The main render window the game will take place in
    Window MainWindow(800, 600, "Dungeon Escape");
}



using namespace Common::Textures; //Prevents me from having to type Common::Textures everywhere 

//Creates all the common sprites used in the game
void Common::CreateSprites()
{
    Sprites::centerPiece1 = CreateSprite(centerPiece1);
    Sprites::centerPiece2 = CreateSprite(centerPiece2);

    Sprites::topJointPiece = CreateSprite(topJointPiece);
    Sprites::bottomJointPiece = CreateSprite(bottomJointPiece);
    Sprites::leftJointPiece = CreateSprite(leftJointPiece);
    Sprites::rightJointPiece = CreateSprite(rightJointPiece);

    Sprites::topLeftPiece = CreateSprite(topLeftPiece);
    Sprites::topRightPiece = CreateSprite(topRightPiece);
    Sprites::bottomLeftPiece = CreateSprite(bottomLeftPiece);
    Sprites::bottomRightPiece = CreateSprite(bottomRightPiece);
    Sprites::topPiece = CreateSprite(topPiece);
    Sprites::bottomPiece = CreateSprite(bottomPiece);
    Sprites::rightPiece = CreateSprite(rightPiece);
    Sprites::leftPiece = CreateSprite(leftPiece);
}

//Gets a random sprite that can be used as a center tile
smk::Sprite Common::GetCenterSprite()
{
    //Pick a random number between 0 and 1
    int random = RandomNumber(0, 2);

    //The sprite we are going to select
    Sprite selectedSprite;

    //If the number is zero
    if (random == 0)
    {
        //Pick centerPiece1
        selectedSprite = Sprites::centerPiece1;
    }
    //If the number is one
    else
    {
        //Pick centerPiece2
        selectedSprite = Sprites::centerPiece2;
    }

    //Apply a random rotation to the sprite to vary it even more
    selectedSprite.SetRotation(DirectionToDegrees(RandomDirection()));

    //Return the selected sprite
    return selectedSprite;
}

//Gets a joint sprite that can be used as a joint piece pointing in a specified direction
//SourceDirection : The direction where the joint is going
//To : The direction the joint is to redirect to

//IMPORTANT NOTE : In SFML, The negative y-axis points upwards, not downwards, because the y-axis starts at the top of the screen.
//                 This means that down points up, and up points down, so this will affect which sprite we choose
smk::Sprite Common::GetJointPiece(Direction sourceDirection, Direction to)
{
    //The selected joint sprite
    smk::Sprite joint = Common::Sprites::topJointPiece;

    switch (sourceDirection)
    {
        //If the source direction is going up
    case Direction::Up:
        //If the destination direction is to go left
        if (to == Direction::Left)
        {
            //Set the sprite to the left join piece
            joint = Common::Sprites::leftJointPiece;

            //Return the joint piece
            return joint;
        }
        //If the destination direction is to go right
        else if (to == Direction::Right)
        {
            //Set the sprite to the right join piece
            joint = Common::Sprites::rightJointPiece;

            //Return the joint piece
            return joint;
        }
        break;
        //If the source direction is going right
    case Direction::Right:
        //If the destination direction is to go down
        if (to == Direction::Down)
        {
            //Set the sprite to the top right joint piece
            joint = Common::Sprites::topJointPiece;

            //Flip the sprite horizontally so it's the top-left piece
            joint.SetScale(-1.0f,1.0f);

            //Return the joint piece
            return joint;
        }
        //If the destination direction is to go up
        else if (to == Direction::Up)
        {
            //Set the sprite to the bottom right joint piece
            joint = Common::Sprites::bottomJointPiece;
            //Flip the sprite horizontally so it's the bottom-left piece
            joint.SetScale(-1.0f, 1.0f);

            //Return the joint piece
            return joint;
        }
        break;
        //If the source direction is going down
    case Direction::Down:
        //If the destination direction is to go left
        if (to == Direction::Left)
        {
            //Set the sprite to the bottom right joint piece
            joint = Common::Sprites::bottomJointPiece;
            //Flip the sprite horizontally so it's the bottom-left piece
            joint.SetScale(-1.0f, 1.0f);

            //Return the joint piece
            return joint;
        }
        //If the destination direction is to go right
        else if (to == Direction::Right)
        {
            //Set the sprite to the bottom right joint piece
            joint = Common::Sprites::bottomJointPiece;

            //Return the joint piece
            return joint;
        }
        break;
        //If the source direction is going left
    case Direction::Left:
        //If the destination direction is to go down
        if (to == Direction::Down)
        {
            //Set the sprite to the top right joint piece
            joint = Common::Sprites::topJointPiece;

            //Return the joint piece
            return joint;
        }
        //If the destination direction is to go up
        else if (to == Direction::Up)
        {
            //Set the sprite to the bottom right joint piece
            joint = Common::Sprites::bottomJointPiece;

            //Return the joint piece
            return joint;
        }
        break;
    }
    return joint;
}

//Gets a sprite that represents a side wall
//IMPORTANT NOTE : In SFML, The negative y-axis points upwards, not downwards, because the y-axis starts at the top of the screen.
//                 This means that down points up, and up points down, so this will affect which sprite we choose
smk::Sprite Common::GetSideSprite(Direction side)
{
    switch (side)
    {
        //If we want the top wall side
    case Direction::Up:
        return Sprites::bottomPiece;

        //If we want the right wall side
    case Direction::Right:
        return Sprites::rightPiece;

        //If we want the bottom wall side
    case Direction::Down:
        return Sprites::topPiece;

        //If we want the left wall side
    case Direction::Left:
        return Sprites::leftPiece;
    }
    return Sprites::topPiece;
}

//Gets a sprite that represents a corner
//IMPORTANT NOTE : In SFML, The negative y-axis points upwards, not downwards, because the y-axis starts at the top of the screen.
//                 This means that down points up, and up points down, so this will affect which sprite we choose
smk::Sprite Common::GetCornerSprite(Direction A, Direction B)
{
    switch (A)
    {
        //If we are getting corner that is on the top side
    case Direction::Up:
        //If we are getting corner that is also on the left side
        if (B == Direction::Left)
        {
            //Return the bottom-left corner
            return Sprites::bottomLeftPiece;
        }
        //If we are getting corner that is also on the right side
        else if (B == Direction::Right)
        {
            //Return the bottom-right corner
            return Sprites::bottomRightPiece;
        }
        break;
        //If we are getting corner that is on the right side
    case Direction::Right:
        //If we are getting corner that is also on the top side
        if (B == Direction::Up)
        {
            //Return the bottom-right corner
            return Sprites::bottomRightPiece;
        }
        //If we are getting corner that is also on the bottom side
        else if (B == Direction::Down)
        {
            //Return the top-right corner
            return Sprites::topRightPiece;
        }
        break;
        //If we are getting corner that is on the bottom side
    case Direction::Down:
        //If we are getting corner that is also on the left side
        if (B == Direction::Left)
        {
            //Return the top-left corner
            return Sprites::topLeftPiece;
        }
        //If we are getting corner that is also on the right side
        else if (B == Direction::Right)
        {
            //Return the top-right corner
            return Sprites::topRightPiece;
        }
        break;
        //If we are getting corner that is on the left side
    case Direction::Left:
        //If we are getting corner that is also on the top side
        if (B == Direction::Up)
        {
            //Return the bottom-left corner
            return Sprites::bottomLeftPiece;
        }
        //If we are getting corner that is also on the bottom side
        else if (B == Direction::Down)
        {
            //Return the top-left corner
            return Sprites::topLeftPiece;
        }
        break;
    }
    //Return the top-left if no matches above were made
    return Sprites::topLeftPiece;
}

/*Vector2f transformPoint(const glm::mat4 m_matrix, float x, float y)
{
    return Vector2f(m_matrix[0] * x + m_matrix[4] * y + m_matrix[12],
        m_matrix[1] * x + m_matrix[5] * y + m_matrix[13]);
}


////////////////////////////////////////////////////////////
Vector2f transformPoint(const glm::mat4 m_matrix, const Vector2f& point)
{
    return transformPoint(point.x, point.y);
}


////////////////////////////////////////////////////////////
FloatRect transformRect(const glm::mat4 m_matrix, const FloatRect& rectangle)
{
    // Transform the 4 corners of the rectangle
    const Vector2f points[] =
    {
        transformPoint(rectangle.left, rectangle.top),
        transformPoint(rectangle.left, rectangle.top + rectangle.height),
        transformPoint(rectangle.left + rectangle.width, rectangle.top),
        transformPoint(rectangle.left + rectangle.width, rectangle.top + rectangle.height)
    };

    // Compute the bounding rectangle of the transformed points
    float left = points[0].x;
    float top = points[0].y;
    float right = points[0].x;
    float bottom = points[0].y;
    for (int i = 1; i < 4; ++i)
    {
        if (points[i].x < left)   left = points[i].x;
        else if (points[i].x > right)  right = points[i].x;
        if (points[i].y < top)    top = points[i].y;
        else if (points[i].y > bottom) bottom = points[i].y;
    }

    return FloatRect(left, top, right - left, bottom - top);
}*/

FloatRect getLocalBounds(const smk::Sprite& sprite)
{
    float width = static_cast<float>(std::abs(sprite.texture().width()));
    float height = static_cast<float>(std::abs(sprite.texture().height()));

    return FloatRect(0.f, 0.f, width, height);
}

Vector2f transformPoint(const glm::mat4 m_matrix, float x, float y)
{
    auto point = glm::vec4(x, y, 0, 0);
    auto output = m_matrix * point;

    return Vector2f(point.x, point.y);
    //return transformPoint(point.x, point.y);
}


FloatRect getGlobalBounds(const smk::Sprite& sprite)
{
    auto rectangle = getLocalBounds(sprite);
    auto transform = sprite.transformation();
    const Vector2f points[] =
    {
        transformPoint(transform, rectangle.left, rectangle.top),
        transformPoint(transform, rectangle.left, rectangle.top - rectangle.height),
        transformPoint(transform, rectangle.left + rectangle.width, rectangle.top),
        transformPoint(transform, rectangle.left + rectangle.width, rectangle.top - rectangle.height)
    };

    // Compute the bounding rectangle of the transformed points
    float left = std::get<0>(points[0]);
    float top = std::get<1>(points[0]);
    float right = std::get<0>(points[0]);
    float bottom = std::get<1>(points[0]);
    for (int i = 1; i < 4; ++i)
    {
        if (std::get<0>(points[i]) < left)   left = std::get<0>(points[i]);
        else if (std::get<0>(points[i]) > right)  right = std::get<0>(points[i]);
        if (std::get<1>(points[i]) < top)    top = std::get<1>(points[i]);
        else if (std::get<1>(points[i]) > bottom) bottom = std::get<1>(points[i]);
    }

    return FloatRect(left, top, right - left, bottom - top);
    //sprite.transformation()
    //return getTransform().transformRect(getLocalBounds(sprite));
}

//Checks whether two sprites intersect. Optionally scaling their hitboxes by a scale factor
bool Common::SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B, Vector2f scaleFactor)
{
    //Get the global bounds of sprite A
    auto rectA = getGlobalBounds(A);
    //Get the global bounds of sprite B
    auto rectB = getGlobalBounds(B);

    //Scale their bounds by the specified scale factor
    rectA.left *= std::get<0>(scaleFactor);
    rectA.top *= std::get<1>(scaleFactor);
    rectB.top *= std::get<1>(scaleFactor);
    rectB.left *= std::get<0>(scaleFactor);

    //Check if they intersect
    return Math::RectsIntersect(rectA, rectB);
}

//Checks whether two sprites intersect
bool Common::SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B)
{
    return Common::SpritesIntersect(A, B, { 1.0f,1.0f });
}

//Checks whether two sprites intersect. Optionally scaling their hitboxes by their texture sizes if set to true
bool Common::SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B, bool scaleByTextureSize)
{
    Vector2f scaleFactor(1.0f, 1.0f);
    //If they are to be scaled based on their texture size
    if (scaleByTextureSize)
    {
        //Get the texture rect
        auto textureRect = Rect<int>(0,0,A.texture().width(), A.texture().height());
        //auto textureRect = A.getTextureRect();
        //Set the scale factor to the texture rect
        std::get<0>(scaleFactor) = textureRect.width;
        std::get<1>(scaleFactor) = textureRect.height;
    }

    return Common::SpritesIntersect(A, B, scaleFactor);
}

//Refreshes the size of the window. This is normally used when the window gets resized
void Common::RefreshWindow(smk::Window& window)
{
    //Get the current window view
    auto view = window.view();
    //Reset the view's size
    //view.SetSize(static_cast<smk::Vector2f>(window.getSize() / 3u));
    view.SetSize(window.width() / 3, window.height() / 3);
    //Set the window's view to the new one
    window.SetView(view);

}

//Gets the mouse position in world coordinates
Vector2f Common::GetMouseWorldCoordinates(smk::Window& window)
{
    //Gets the mouse's desktop position, subtracts the window position to get the window position of the mouse, and then maps that position to world coordinates
    //return window.mapPixelToCoords(Mouse::getPosition() - window.getPosition());
    //auto mousePos = smk::Input::mouse();
    auto mousePos = window.input().cursor();

    return Vector2f(mousePos.x,mousePos.y);
}

//Centers the camera over a specified point
void Common::CenterCamera(Vector2f center, smk::Window& window)
{
    //Get the currently set view
    auto view = window.view();

    view.SetCenter(std::get<0>(center), std::get<1>(center));

    //Update the window's view with the new view
    window.SetView(view);
}



bool randomRanOnce = false; //Whether the randomizer has been run at least once already

//Gets a random number between the minRange (inclusive) and the maxRange (exclusive)
int Common::RandomNumber(int minRange, int maxRange)
{
    //If it hasn't been ran already
    if (!randomRanOnce)
    {
        randomRanOnce = true;
        //Reset the starting seed
        srand(static_cast<unsigned int>(time(0)));
    }

    //Return a random number between the two ranges
    return (rand() % (maxRange - minRange)) + minRange;
}
