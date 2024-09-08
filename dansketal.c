#include "dansketal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *ones[] = {"", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"};
const char *teens[] = {"ti", "elve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
const char *tens[] = {"", "", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfems"};
const char *hundred = "hundrede";
const char *thousand = "tusinde";
const char *million = "million";
const char *billion = "milliard";
const char *minus = "minus";

void append_to_buffer(char *buffer, const char *str) {
    if (strlen(buffer) > 0) {
        strcat(buffer, " ");
    }
    strcat(buffer, str);
}

void number_to_words(int n, char *buffer, NumberFormat format) {
    if (n < 0) {
        append_to_buffer(buffer, minus);
        n = -n;
    }

    if (n == 0) {
        append_to_buffer(buffer, "nul");
        return;
    }

    if (n >= 1000000000) {
        number_to_words(n / 1000000000, buffer, format);
        append_to_buffer(buffer, billion);
        n %= 1000000000;
    }

    if (n >= 1000000) {
        number_to_words(n / 1000000, buffer, format);
        append_to_buffer(buffer, million);
        n %= 1000000;
    }

    if (n >= 1000) {
        int thousands = n / 1000;
        if (thousands != 1 || !format.et_prefix) {
            number_to_words(thousands, buffer, format);
        }
        append_to_buffer(buffer, thousand);
        n %= 1000;
    }

    if (n >= 100) {
        int hundreds = n / 100;
        if (hundreds != 1 || !format.et_prefix) {
            number_to_words(hundreds, buffer, format);
        }
        append_to_buffer(buffer, hundred);
        n %= 100;
    }

    if (n >= 20) {
        int tens_place = n / 10;
        int ones_place = n % 10;
        if (ones_place > 0) {
            append_to_buffer(buffer, ones[ones_place]);
        }
        append_to_buffer(buffer, tens[tens_place]);
        return;
    }

    if (n >= 10) {
        append_to_buffer(buffer, teens[n - 10]);
    } else if (n > 0) {
        append_to_buffer(buffer, ones[n]);
    }
}

void dansketal(int n, char *buffer, NumberFormat format) {
    buffer[0] = '\0'; // Null-terminate buffer
    number_to_words(n, buffer, format);
}