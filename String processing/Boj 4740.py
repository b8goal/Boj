while True:
    _ = input()
    if _ == '***':
        break
    else:
        print(''.join(reversed(_)))