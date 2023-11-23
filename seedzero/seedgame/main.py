import pygame
from player import Player

pygame.init() 
screen = pygame.display.set_mode((800, 600))


def main():
    player = Player(screen=screen)
    while True: #1loop=1frame
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN :#detectการกดว่าแบบไปซ้ายขวาบน
                if event.key == pygame.K_w: #กดwแล้วตัวกล่องมันขึ้น
                    player.update_speed_y(-1) #+speedเพราะถ้าไม่มีพอกดบนล่างพร้อมกันมันจะไม่หยุดทั้งที่ความจริงมันควรจะหยุด
                if event.key == pygame.K_s:
                    player.update_speed_y(1)
                if event.key == pygame.K_a:
                    player.update_speed_x(-1)
                if event.key == pygame.K_d:
                    player.update_speed_x(1)
            if event.type == pygame.KEYUP: #มีไว้ให้มันแบบว่าหยุดได้มั้ง ถ้าไม่มีกล่องมันไม่หยุดวิ่ง
            #detectการหยุดกดว่าแบบถ้าหยุดละมันก้หยุดวิ่งงี้
                if event.key == pygame.K_w:
                    player.update_speed_y(1)
                if event.key == pygame.K_s:
                    player.update_speed_y(-1)
                if event.key == pygame.K_a:
                    player.update_speed_x(1)
                if event.key == pygame.K_d:
                    player.update_speed_x(-1)
        player.update_player_pos()
        screen.fill("violet")
        player.render()
        #pygame.draw.rect(screen,"black",(player_pos_x,player_pos_y,player_width,player_height)) #ใส่สีกับตัวเริ่มต้นของสี่เหลี่ยม ตอนนี้ให้มันอยู่มุมบนซ้ายสุดก็คือ0,0
        pygame.display.update()

main()