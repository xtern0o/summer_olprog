# Конь стоит на шахматной доске какого-то огромного размера.
# Найти минимальное количество ходов до данной клетки


def moves(x, y):
    return [
        (x - 2, y + 1), (x - 2, y - 1),
        (x - 1, y + 2), (x - 1, y - 2),
        (x + 1, y + 2), (x + 1, y - 2),
        (x + 2, y + 1), (x + 2, y - 1),
    ]


def find_dist(tx, ty):
    layer_num = 0
    prev_layer, curr_layer = set(), set([(0, 0)])
    while (tx, ty) not in curr_layer:
        next_layer = set()
        for (x, y) in curr_layer:
            for next_cell in moves(x, y):
                if next_cell not in prev_layer:
                    next_layer.add(next_cell)
        prev_layer, curr_layer = curr_layer, next_layer
        layer_num += 1
    return layer_num