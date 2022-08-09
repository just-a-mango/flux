import os
try:
    import keyboard
except:
    os.system("pip install keyboard")
    os.system("python flux-hub.py")
    exit()
    
selected = 1


def starter_menu():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("\033[35m"+"  Flux Hub 🏠     "+"\033[0m")
    print("\033[36m     > Create starter file\033[0m")
    print("    > Update Flux")
    print("    > Uninstall Flux")

def show_menu(key):
    os.system('cls' if os.name == 'nt' else 'clear')
    print("\033[35m"+"  Flux Hub 🏠     "+"\033[0m")
    if key == 1:
        print("\033[36m     > Create starter file\033[0m")
        print("    > Update Flux")
        print("    > Uninstall Flux")
    elif key == 2:
        print("    > Create starter file")
        print("\033[36m     > Update Flux\033[0m")
        print("    > Uninstall Flux")
    elif key == 3:
        print("    > Create starter file")
        print("    > Update Flux")
        print("\033[36m     > Uninstall Flux\033[0m")

def up():
    global selected
    if selected == 1:
        return
    selected -= 1
    show_menu(selected)

def down():
    global selected
    if selected == 3:
        return
    selected += 1
    show_menu(selected)

def select():
    if selected == 1:
        with open('starter.flux', 'w') as f:
            f.write('declare myvar = Hello World\nprint -> myvar')
        print("[+] Starter file created")
    elif selected == 2:
        print("/!\ WIP feature")
    elif selected == 3:
        pass
        # os.remove("flux.py")
        
starter_menu()
keyboard.add_hotkey('up', up)
keyboard.add_hotkey('down', down)
keyboard.add_hotkey('enter', select)
keyboard.wait()
