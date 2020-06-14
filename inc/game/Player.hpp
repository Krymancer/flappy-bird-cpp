#include <engine/LTexture.hpp>
#include <engine/engine.hpp>
#include <game/Enemy.hpp>

#pragma once

class Player {
   public:
    Player();
    ~Player();

    /**
    *  Initilizate the texture
    * 
    *  @returns if the initialization was sucessfully
    */
    bool init();

    /// Update method
    void update();

    /// Show the car texture
    void show();

    /// Make the player jumps
    void jump();

    /// Reset player position
    void reset();

    /// Think
    void think(Enemy &pipe);

    /**
    *  Check if the player collides with a enemy
    * 
    *  @param enemy the enemy to check
    * 
    *  @returns true with collides
    */
    bool collide(Enemy &enemy);

   private:
    LTexture mTexture;
    int x, y;

    double velocityY = -9.0;          // Player's velocity along Y, default same as flapped;
    double maxVelocityY = 10.0;       // Max velocity along Y, max descend speed
    double minVelocityY = -8.0;       // Min velocity along X, max ascend speed
    double acclerationY = 1.0;        // Player's downward accleration
    double rotationAngle = -45.0;     // Player's rotation
    double visibleRotation = 0;       // Player's visible rotation
    double velocityRotation = 6.0;    // Angular Speed
    double rotationThreshold = 20.0;  // Rotation Trheshold
    double flappyAccleration = -9.0;  // Player's speed on flapping
    bool flapped = false;             // True when player flaps

    int frame = 0;
    const int FLY_ANIMATION_FRAMES = 3;
    SDL_Rect spritesClips[3];
};