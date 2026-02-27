/*
 * report.hpp  (CPP Practice / Behavior Playground)
 *
 * Created by Durand Dyer-Branch on 2/25/26.
 *
 * Purpose
 * -------
 * A tiny, header-only "report printer" used by C++ Behavior Playground experiments.
 * Each experiment is a standalone executable (one .cpp -> one target). This header
 * provides lightweight helpers to print a standardized, repeatable lab report so
 * experiments stay focused on C++ behavior rather than formatting boilerplate.
 *
 * Report Format (fixed order)
 * ---------------------------
 * 1) Scenario header
 *    - id
 *    - one-sentence goal (tied to C++ Primer 5e §2.1)
 * 2) Inputs
 *    - variables/literals/expressions with declared types and initial values
 * 3) Evaluation pipeline (stages a–d)
 *    a) Representation / Range (sizeof, numeric_limits, signedness)
 *    b) Promote (integer promotions / usual arithmetic conversions / to-bool)
 *    c) Compute (operation type + computed value)
 *    d) Convert / Assign (target type + stored value + classification)
 * 4) Behavior classification
 *    - well-defined / implementation-defined / undefined / ill-formed
 * 5) Rule summary (invariant)
 *    - 1–3 short sentences stating the takeaway rule
 *
 * Design Constraints
 * ------------------
 * - No inheritance, no complex abstractions.
 * - Header-only, easy to include in many small executables.
 * - Helpers print structure and observables; they do NOT "solve" the experiment.
 *   You still write the promotion/conversion reasoning lines per scenario.
 *
 * Typical Use
 * -----------
 *   #include "report.hpp"
 *   int main() {
 *     rpt::header("2.1.conv.negative_to_unsigned_modulo", "...rule...");
 *     rpt::inputs({ "int i = -1", "unsigned u (assign u=i)" });
 *     rpt::pipeline_begin();
 *     rpt::stage("a) Representation / Range stage");
 *     rpt::repr_range<unsigned>("unsigned");
 *     rpt::prompt_prediction();
 *     ...
 *   }
 */

#ifndef CPP_PRACTICE_REPORT_H
#define CPP_PRACTICE_REPORT_H

#include <iostream>      // std::cout, std::cin
#include <initializer_list>
#include <string_view>
#include <climits>
#include <limits>        // std::numeric_limits
#include <type_traits>   // std::is_floating_point_v
using namespace std;

namespace rpt {
/// Print the required "Scenario header" section.
/// - id: stable scenario identifier (e.g., "2.1.conv.negative_to_unsigned_modulo")
/// - goal: one-sentence statement of the rule being demonstrated (linked to §2.1)
inline void header(std::string_view id, std::string_view goal) {
    std::cout << "1) Scenario header\n";
    std::cout << "id: " << id << "\n";
    std::cout << "goal: " << goal << "\n\n";
}

/// Print the required "Inputs" section.
/// Pass a list of human-readable lines describing variables/literals/expressions.
/// Example:
///   inputs({"int i = -1", "unsigned u (will assign)", "expression: u = i"});
inline void inputs(std::initializer_list<std::string_view> lines) {
    std::cout << "2) Inputs\n";
    for (auto s : lines) std::cout << "- " << s << "\n";
    std::cout << "\n";
}

/// Print the heading for the evaluation pipeline section.
/// You still print stages a–d below this, even if some are "(n/a)".
inline void pipeline_begin() {
    std::cout << "3) Evaluation pipeline\n";
}

/// Print a pipeline stage label (e.g., "a) Representation / Range stage").
/// Use this to enforce consistent structure across scenarios.
inline void stage(std::string_view label) {
    std::cout << label << "\n";
}

/// Print a single informational line inside a section/stage.
/// Use for explanations of promotions, conversions, operation types, etc.
inline void note(std::string_view line) {
    std::cout << line << "\n";
}

/// Print a blank line.
/// Useful to visually separate stages or sub-blocks without changing structure.
inline void blank() {
    std::cout << "\n";
}

/// Print the required "Behavior classification" section.
/// Each line should label a key step as:
/// - well-defined
/// - implementation-defined
/// - undefined
/// - ill-formed
inline void classify(std::initializer_list<std::string_view> lines) {
    std::cout << "\n4) Behavior classification\n";
    for (auto s : lines) std::cout << "- " << s << "\n";
    std::cout << "\n";
}

/// Print the required "Rule summary (invariant)" section.
/// Keep to 1–3 short bullet points that summarize what the scenario proved.
inline void rule(std::initializer_list<std::string_view> lines) {
    std::cout << "5) Rule summary (invariant)\n";
    for (auto s : lines) std::cout << "- " << s << "\n";
    std::cout << "\n";
}

/// Print a short reminder to make a prediction before running/entering inputs.
/// This does NOT compute anything; it's just a workflow nudge to protect learning.
inline void prompt_prediction(std::string_view what_to_predict =
    "Predict: does it compile, what prints, and which steps are defined / implementation-defined / undefined.")
{
    std::cout << "\n[Prediction checkpoint]\n";
    std::cout << what_to_predict << "\n\n";
}

/// Print "key: value" without forcing callers to build strings.
/// This is intentionally minimal: it relies on operator<< for the value type.
/// Example:
///   kv(\"unsigned max = \", std::numeric_limits<unsigned>::max());
template <class T>
inline void kv(std::string_view key, const T& value) {
    std::cout << key << value << "\n";
}

/// Print observable representation/range facts for a type.
/// Intended for stage (a): sizeof, signedness, and min/max.
/// Notes:
/// - For floating types, numeric_limits<T>::min() is the smallest *positive* normalized value,
///   so we print lowest() (most negative) and max(), plus digits10.
/// - For integral types, we print min() and max().
template <class T>
inline void repr_range(std::string_view name) {
    std::cout << name << ":\n";
    kv("  bytes = ", sizeof(T));
    kv("  bits per byte = " , CHAR_BIT);
    kv("  bits in type = ", sizeof(T) * CHAR_BIT);

    kv("  is_signed = ", std::numeric_limits<T>::is_signed);

    kv("  Decimal digits precision = ", std::numeric_limits<T>::digits10);
    kv("  Binary digit precision = ", numeric_limits<T>::digits);

    if constexpr (std::is_floating_point_v<T>) {
        kv("  lowest   = ", std::numeric_limits<T>::lowest());
        kv("  max      = ", std::numeric_limits<T>::max());
        kv("  Decimal digits precision = ", std::numeric_limits<T>::digits10);
        kv("  Binary digit precision = ", numeric_limits<T>::digits);
        kv("  Max digit precision = " , numeric_limits<T>::max_digits10);
    } else {
        kv("  min = ", std::numeric_limits<T>::min());
        kv("  max = ", std::numeric_limits<T>::max());
    }
}

/// Read a value of type T from std::cin with basic recovery on failure.
/// Returns:
/// - true if a value of type T was successfully extracted
/// - false if extraction failed (non-numeric input, out-of-range for T, etc.)
///
/// On failure, this:
/// - clears the stream error flags
/// - discards the rest of the current line (so the next attempt starts fresh)
///
/// This is usually preferable to try/catch for interactive numeric input.
template <class T>
inline bool read_value(std::string_view prompt, T& out) {
    std::cout << prompt;
    if (std::cin >> out) return true;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

/// Check whether the next non-whitespace character in stdin is 'q' or 'Q'.
/// This lets experiments support "q to quit" without building a full parser.
///
/// Important: This only *peeks*; it does not consume the character.
/// Typical usage:
///   if (next_is_quit()) { char q; std::cin >> q; break; }
inline bool next_is_quit() {
    std::cin >> std::ws;          // consume leading whitespace
    int c = std::cin.peek();      // look at next char without extracting
    return c == 'q' || c == 'Q';
}

} // namespace rpt

#endif // CPP_PRACTICE_REPORT_H