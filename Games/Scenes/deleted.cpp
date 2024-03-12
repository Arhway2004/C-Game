// void Level1::updateBulletEnemiesCollision(const float& dt){
//     for (auto bullet = this->bullets.begin(); bullet != this->bullets.end();) {
//         bullet->update(dt, this->player->bulletAngles[std::distance(this->bullets.begin(), bullet)]);

//         if (bullet->isOutBound()) {
//             bullet = this->bullets.erase(bullet);
//             this->player->bulletAngles.erase(this->player->bulletAngles.begin() + std::distance(this->bullets.begin(), bullet));
//         } else {
//             bool bulletHitEnemy = false;
//             for (auto enemy = this->enemies.begin(); enemy != this->enemies.end();) {
//                 if (this->bulletHitEnemy(*bullet, *enemy)) {
//                     bullet = this->bullets.erase(bullet);
//                     this->player->bulletAngles.erase(this->player->bulletAngles.begin() + std::distance(this->bullets.begin(), bullet));
//                     enemy = this->enemies.erase(enemy);
//                     // enemy->setState(Enemy::EnemyStates::DAMAGED);
//                     // enemy->update(dt, this->mousePosView);
//                     // if(enemy->getState() == Enemy::EnemyStates::DEAD){
//                     //     enemy = this->enemies.erase(enemy);
//                     // }
//                     bulletHitEnemy = true;
//                     std::cout << "Bullet hit Enemy" << std::endl;
//                 } else {
//                     ++enemy;
//                 }
//             }
//             if (!bulletHitEnemy) {
//                 ++bullet;
//             }
//         }
//     }
// }



// for(size_t j = 0; j < this->enemies.size(); j++){
//             if(this->bulletHitEnemy(this->bullets[i], this->enemies[j])){
//                 this->killCount++;
//                 this->bullets.erase(this->bullets.begin() + i);
//                 this->player->bulletAngles.erase(this->player->bulletAngles.begin() + i);
//                 this->enemies.erase(this->enemies.begin() + j);
//                 // this->enemies[j].setState(Enemy::EnemyStates::DAMAGED);
//                 // this->enemies[j].updateState();
//                 // if(enemies[j].getState() == Enemy::EnemyStates::DEAD){
//                 //     this->enemies.erase(this->enemies.begin() + j);
//                 // }
//                 std::cout << "Bullet hit Enemy" << std::endl;
//             }
//         }



//urgent
//background/music
//enter to continue : firstscene
//win/lose
//during gameplay, user press option = game pause
//hui setting scene in option
//other button in option
//Setting in option not show anything