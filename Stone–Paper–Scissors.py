import random

def play_game():
    print("Welcome to Stone Paper Scissors!")
    print("Options: stone, paper, scissors")
    
    user_choice = input("Enter your choice: ").lower()
    choices = ['stone', 'paper', 'scissors']
    computer_choice = random.choice(choices)
    
    print(f"\nYou chose: {user_choice}")
    print(f"Computer chose: {computer_choice}")

    if user_choice == computer_choice:
        print("It's a tie!")
    elif (
        (user_choice == 'stone' and computer_choice == 'scissors') or
        (user_choice == 'paper' and computer_choice == 'stone') or
        (user_choice == 'scissors' and computer_choice == 'paper')
    ):
        print("🎉 You win!")
    elif user_choice not in choices:
        print("Invalid choice! Please choose stone, paper, or scissors.")
    else:
        print("😢 Computer wins!")

# Run the game
play_game()
