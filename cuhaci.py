import tkinter as tk
from tkinter import messagebox

# Initialize main window
root = tk.Tk()
root.title("Tic Tac Toe - Home Screen")

# Function to handle Start button
def start_game():
    if not (board_var.get() and player_var.get() and length_var.get() and time_var.get()):
        messagebox.showerror("Error", "Please select a board size, time, length and number of players.")
        return
    if board_var.get() == "3x3" and length_var.get() in ["4", "5"]:
        messagebox.showwarning("Warning", "Board size 3x3 is too small for length 4 or 5.")
        return
    options = {
        "Board Size": board_var.get(),
        "Players": player_var.get(),
        "Time Limit": time_var.get(),
        "Blocked": blocked_var.get(),
        "Joker": joker_var.get(),
        "Length": length_var.get()
    }
    print("Game Options:", options)
    # Proceed to start the game
    root.destroy()

# Frames for organizing layout
main_frame = tk.Frame(root)
main_frame.pack(pady=10, padx=10)

left_frame = tk.Frame(main_frame)
left_frame.grid(row=0, column=0, padx=10, pady=10, sticky="n")
right_frame = tk.Frame(main_frame)
right_frame.grid(row=0, column=1, padx=10, pady=10, sticky="n")

# Board size checkboxes
board_frame = tk.LabelFrame(left_frame, text="Board Size")
board_frame.pack(pady=10)
board_var = tk.StringVar()
board_var.set("")
for size in ["3x3", "5x5", "7x7"]:
    tk.Radiobutton(board_frame, text=size, variable=board_var, value=size).pack(anchor="w")

# Player mode checkboxes
player_frame = tk.LabelFrame(left_frame, text="Players")
player_frame.pack(pady=10)
player_var = tk.StringVar()
player_var.set("")
for players in ["2 Player", "3 Player"]:
    tk.Radiobutton(player_frame, text=players, variable=player_var, value=players).pack(anchor="w")

# Time limit checkboxes
time_frame = tk.LabelFrame(left_frame, text="Time Limit")
time_frame.pack(pady=10)
time_var = tk.StringVar()
time_var.set("")
for limit in ["6 seconds", "12 seconds","None"]:
    tk.Radiobutton(time_frame, text=limit, variable=time_var, value=limit).pack(anchor="w")


# Other options
options_frame = tk.LabelFrame(right_frame, text="Options")
options_frame.pack(pady=10)
blocked_var = tk.BooleanVar()
joker_var = tk.BooleanVar()
tk.Checkbutton(options_frame, text="Blocked", variable=blocked_var).pack(anchor="w")
tk.Checkbutton(options_frame, text="Joker", variable=joker_var).pack(anchor="w")

# Length selection
length_frame = tk.LabelFrame(right_frame, text="Length")
length_frame.pack(pady=10)
length_var = tk.StringVar()
length_var.set("")
for length in ["3", "4", "5"]:
    tk.Radiobutton(length_frame, text=length, variable=length_var, value=length).pack(anchor="w")

# Start button
start_button = tk.Button(root, text="Start Game", command=start_game)
start_button.pack(pady=20)

# Run the application
root.mainloop()





