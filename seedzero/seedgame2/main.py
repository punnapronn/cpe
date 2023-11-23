import pygame
from player import Player
from time import sleep

pygame.init()
screen = pygame.display.set_mode((800, 600))

FPS = 60
clock = pygame.time.Clock()

font = pygame.font.SysFont("Arial", 20, True)


def main():
    player1 = Player(screen=screen, speed=5, is_player1=True ,image_path="น้องน้ำ.png")
    player2 = Player(width=200, height=350,
                     pos_x=screen.get_width()-75, pos_y=screen.get_height()-75,
                     screen=screen, speed=5, is_player1=False,image_path="น้องอีฟ.png")

    time_left = 10

    is_running = True

    while is_running:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_w:
                    player1.update_speed_y(-1)
                if event.key == pygame.K_a:
                    player1.update_speed_x(-1)
                if event.key == pygame.K_s:
                    player1.update_speed_y(1)
                if event.key == pygame.K_d:
                    player1.update_speed_x(1)

                if event.key == pygame.K_UP:
                    player2.update_speed_y(-1)
                if event.key == pygame.K_LEFT:
                    player2.update_speed_x(-1)
                if event.key == pygame.K_DOWN:
                    player2.update_speed_y(1)
                if event.key == pygame.K_RIGHT:
                    player2.update_speed_x(1)

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_w:
                    player1.update_speed_y(1)
                if event.key == pygame.K_a:
                    player1.update_speed_x(1)
                if event.key == pygame.K_s:
                    player1.update_speed_y(-1)
                if event.key == pygame.K_d:
                    player1.update_speed_x(-1)

                if event.key == pygame.K_UP:
                    player2.update_speed_y(1)
                if event.key == pygame.K_LEFT:
                    player2.update_speed_x(1)
                if event.key == pygame.K_DOWN:
                    player2.update_speed_y(-1)
                if event.key == pygame.K_RIGHT:
                    player2.update_speed_x(-1)

        player1.update_position()
        player2.update_position()

        is_player1_in_player2 = player1.is_in_player(player2)

        time_left -= clock.get_time() / 1000

        text = font.render(f"Time left: {time_left:.2f}", True, "black")
        text_rect = text.get_rect()

        if time_left <= 0:
            text = font.render("nong NARM Win!!!", True, "black")
            is_running = False
        elif time_left > 0 and is_player1_in_player2:
            text = font.render("nong EVE Win!!!", True, "black")
            is_running = False

        screen.fill("cyan")
        player1.render()
        player2.render()
        screen.blit(text, (screen.get_width() / 2 - text_rect.width / 2,
                           screen.get_height() / 2 - text_rect.height / 2))
        pygame.display.update()

    sleep(1)
    pygame.quit()
    exit()


main()