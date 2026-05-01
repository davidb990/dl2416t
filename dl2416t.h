#include "hardware/gpio.h"

/** \file dl2416t/dl2416t.h
 * 
 *
 * \brief Driver for the DL2416T display
 */


struct dl2416t {
    unsigned int data_pin[7];
    unsigned int address_pin[2];
    unsigned int clear_n;
    unsigned int write_n;
    unsigned int blank_n;
    unsigned int cursor_en;
    unsigned int cursor_sel;
};


/**
 * \brief Initialse the GPIO pins associated with the display, and give then sensible initial values
 *
 * \param display The display's pins
 */
void dl2416t_setup(struct dl2416t *display);

/**
 * \brief Display a single character on the DL2416T.
 *
 * \param display The display's pins
 * \param character ASCII char to write to the display
 * \param index Index to write to - note that the DL2416T's character indicies go 3, 2, 1, 0 left to right.
 */
void dl2416t_display_char(struct dl2416t *dl2416t, char character, uint8_t index);

/**
 * \brief Display a string on the DL2416T.
 *
 * \param display The display's pins
 * \param string 4 letter string to push to the display
 */
void dl2416t_display_word(struct dl2416t *dl2416t, char string[5]);

/**
 * \brief Display a four characters on the DL2416T by character index
 *
 * \param display The display's pins
 * \param char_0 The character to push onto rightmost digit on the display
 * \param char_1 The character to push onto the inner right digit on the display
 * \param char_2 The character to push onto the inner left digit on the display
 * \param char_3 The character to push onto leftmost digit on the display
 */
void dl2416t_display_chars_all(struct dl2416t *dl2416t, char char_0, char char_1, char char_2, char char_3);


/**
 * \brief Blank or unblank the display
 *
 * \param display The display's pins
 * \param blank_enable true or false
 */
void dl2416t_blank(struct dl2416t *dl2416t, bool blank_enable);
