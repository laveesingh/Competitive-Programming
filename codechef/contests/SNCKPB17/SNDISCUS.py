

class Snake:

    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2

    def horizontal(self):
        return self.y1 == self.y2

    def vertical(self):
        return self.x1 == self.x2

    def dist(self, x, y):
        if self.horizontal():
            first = abs(self.y1 - y)
            second = 0
            if min(self.x1, self.x2) > x or max(self.x1, self.x2) < x:
                second = min(abs(self.x1 - x), abs(self.x2 - x))
            return first + second
        # Now the snake has to be vertical
        first = abs(self.x1 - x)
        second = 0
        if min(self.y1, self.y2) > y or max(self.y1, self.y2) < y:
            second = min(abs(self.y1 - y), abs(self.y2 - y))
        return first + second


t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    snakes = []
    for i in xrange(n):
        x, y, z, w = map(int, raw_input().split())
        snakes.append(Snake(x, y, z, w))
    min_dist = 10**5
    for x in xrange(1, 51):
        for y in xrange(1, 51):
            max_dist = 0
            for snake in snakes:
                max_dist = max(max_dist, snake.dist(x, y))
            min_dist = min(min_dist, max_dist)
    print min_dist