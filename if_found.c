#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
#include <gui/elements.h>
#include <furi_hal.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
} OwnerInfo;

static void render_callback(Canvas* const canvas, void* ctx) {
    furi_assert(ctx);
    OwnerInfo* owner_info = ctx;

    char text[150];

    canvas_set_font(canvas, FontPrimary);

    snprintf(
        text,
        sizeof(text),
        "Owner info:\n%s\n%s\n%s",
        owner_info->name,
        owner_info->email,
        owner_info->phone);

    elements_multiline_text_aligned(canvas, 64, 32, AlignCenter, AlignCenter, text);
}

static void input_callback(InputEvent* input_event, FuriMessageQueue* event_queue) {
    furi_assert(event_queue);

    if(input_event->key == InputKeyBack && input_event->type == InputTypeShort) {
        bool* processing = event_queue;
        *processing = false;
    }
}

int32_t if_found_app() {
    bool processing = true;
    OwnerInfo* owner_info = malloc(sizeof(OwnerInfo));
    strcpy(owner_info->name, "John Doe");
    strcpy(owner_info->email, "johndoe@example.com");
    strcpy(owner_info->phone, "(800) 555-0129");

    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, owner_info);
    view_port_input_callback_set(view_port, input_callback, &processing);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    while(processing) {
        view_port_update(view_port);
        furi_delay_ms(100);
    }

    view_port_enabled_set(view_port, false);
    gui_remove_view_port(gui, view_port);
    furi_record_close(RECORD_GUI);
    view_port_free(view_port);
    free(owner_info);

    return 0;
}