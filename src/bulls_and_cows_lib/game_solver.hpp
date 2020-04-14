
#pragma once

#include "board.hpp"
#include "game_options.hpp"
#include <vector>

namespace bulls_and_cows {

    struct PossibleSolutions
    {
        std::vector<Code> codes;
    };

    PossibleSolutions generate_all_possible_codes(const GameOptions& game_options);

    Code pick_random_attempt(const PossibleSolutions& possible_solutions);

    void remove_incompatible_codes_from_possible_solutions(const AttemptAndFeedback& attempt_and_feedback,
                                                           PossibleSolutions& possible_solutions);

    void all_possible_code(int num, int max, const GameOptions& game_options, PossibleSolutions& var_all_possible_codes,
                           Code codes);
} // namespace bulls_and_cows
