import pygame
class Player:
    def __init__(self,widht=150 , height = 200 , pos_x=0 , pos_y = 0 ,speed = 0.5,screen=None):
        
        self.width = widht
        self.height = height

        self.image = pygame.image.load("น้องน้ำ.png")
        self.image = pygame.transform.scale(self.image,(self.width,self.height))
        
        self.pos_x = pos_x
        self.pos_y = pos_y

        self.speed_x = 0
        self.speed_y = 0
        self.speed = speed
        self.screen = screen

    def update_speed_x(self,direction):
        self.speed_x += direction * self.speed

    def update_speed_y(self,direction):
        self.speed_y += direction * self.speed

    def update_player_pos(self):
        self.pos_x += self.speed_x #อัพเดทตำแหน่งกล่องตามspeed
        self.pos_y += self.speed_y
        self.__manage_player_out_of_screen()

    def __manage_player_out_of_screen(self):
        #เอาไว้ไม่ให้มันหลุดเฟรม ถ้าไปบนเรื่อยๆจนสุดก็จะไปโผล่ล่าง
        if self.pos_x < 0:
            self.pos_x += self.screen.get_width()
        if self.pos_x > self.screen.get_width():
            self.pos_x -= self.screen.get_width()
        if self.pos_y < 0:
            self.pos_y += self.screen.get_width()
        if self.pos_y > self.screen.get_width():
            self.pos_y -= self.screen.get_width()
    def render(self):
        self.screen.blit(self.image,(self.pos_x,self.pos_y))

