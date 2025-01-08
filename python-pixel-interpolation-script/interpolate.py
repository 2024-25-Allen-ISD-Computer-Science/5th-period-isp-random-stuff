def interpolate(x):
  y_prev = 0
  y = eval(equation)
  if (x == 0) or (int(y_prev) == int(y)):
      px(x, yy(y))
  else:
      if int(y_prev) < int(y):
          for w in range(int(y_prev + 1), int(y + 1)):
              px(x, yy(w))
      elif int(y_prev) > int(y):
          for w in range(int(y), int(y_prev)):
              px(x, yy(w))
  y_prev = y
