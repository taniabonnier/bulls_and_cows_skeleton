
#include "game.hpp"
#include "board.hpp"
#include "game_options.hpp"
#include "game_solver.hpp"
#include "input.hpp"
#include "main_menu.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

namespace bulls_and_cows {

    void user_plays_against_computer(const GameOptions& game_options)
    {
        std::cout << "TODO:\n"
                     "    Create a board with a randomly generated secret code\n"
                     "    DO\n"
                     "       Display the board and the list of attempts so far\n"
                     "       Ask the user to make another attempt\n"
                     "       Compare the user's attempt with the secret code and deduce the number of bulls and cows\n"
                     "       Add the user's attempt to the list of attempts of the board\n"
                     "    WHILE not end of game\n"
                     "    Display the board and the list of attempts so far\n"
                     "    Display a message telling if the user won or lost\n";
    }

    void computer_plays_against_computer(const GameOptions& game_options)
    {
        PossibleSolutions all_solutions = generate_all_possible_codes(game_options);
        for (auto tempo : all_solutions.codes)
        {
            std::cout << tempo.value << " ";

        }
        AttemptAndFeedback attempt{};
        attempt.attempt = pick_random_attempt(all_solutions);
        std::cout << "\n" << attempt.attempt.value;
    }

    void configure_game_options(GameOptions& game_options)
    {
        std::cout << "TODO:\n"
                     "    DO\n"
                     "       Display the current game options\n"
                     "       Display the game options menu\n"
                     "       Ask the user to type its choice\n"
                     "       Treat the user's choice\n"
                     "    UNTIL user's choice is to go back to main menu\n";
    }

    void play_game()
    {
        GameOptions game_options{};

        while (true)
        {
            std::cout << "\n#################################\n";
            display_main_menu(std::cout);

            const auto user_choice = ask_main_menu_choice(std::cin);
            switch (user_choice)
            {
            case MainMenuChoice::Quit:
                std::cout << "\nBye bye!\n";
                return;
            case MainMenuChoice::UserPlaysAgainstComputer:
                user_plays_against_computer(game_options);
                break;
            case MainMenuChoice::ComputerPlaysAgainstComputer:
                computer_plays_against_computer(game_options);
                break;
            case MainMenuChoice::ConfigureOptions:
                configure_game_options(game_options);
                break;
            case MainMenuChoice::Error:
                std::cout << "\nYou did not enter a valid choice, please try again\n";
                break;
            }
        }
    }

} // namespace bulls_and_cows
