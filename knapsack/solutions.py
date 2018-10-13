class Item:
  def __init__(self, weight, value):
    self._weight = weight
    self._value = value
  @property
  def weight(self):
    return self._weight
  @property
  def value(self):
    return self._value


class BruteForceKnapSackSolver:
  def __init__(self, weight_limit, items):
    self._weight_limit = weight_limit
    self._items = items
    self._solutions = [0] * len(items)
  
  def solve(self):
    result = self.selectMax(0, 0, 0, self._solutions)
    print(result)
    return
    
  def selectMax(self, actual_weight, actual_value, actual_index, actual_trace):
    if self._weight_limit <= actual_weight or len(items) <= actual_index:
      return (actual_value, actual_trace.copy())

    item = self._items[actual_index]
    not_including = self.selectMax(actual_weight, actual_value, actual_index + 1, actual_trace.copy())

    including = (0, actual_trace.copy())
    if (actual_weight + item.weight <= self._weight_limit):
      actual_trace[actual_index] = 1
      including = self.selectMax(actual_weight + item.weight, actual_value + item.value, actual_index + 1, actual_trace.copy())

      if including[0] < not_including[0]:
        return not_including
      else:
        return including
    return not_including

items = [Item(30, 100), Item(20, 150), Item(10, 200), Item(15, 500), Item(5, 300)]

solver = BruteForceKnapSackSolver(30, items)
solver.solve()

