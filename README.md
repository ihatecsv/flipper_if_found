# Flipper If Found

If Found is a simple application that displays the owner's information on the screen of the device. It's primarily intended for scenarios where the device gets misplaced, allowing a good Samaritan to return the device to its rightful owner.

## How to Use

Once you've started the application, the following information will be displayed on the screen:

1. Owner's name
2. Email address
3. Phone number

You can exit the application by pressing the `Back` button on your device.

![Screenshot](if_found_screenshot.png)

## Compilation

Before you compile the application, please include your information in the source file.

```c
OwnerInfo* owner_info = malloc(sizeof(OwnerInfo));
strcpy(owner_info->name, "Your Name");         // Replace "Your Name" with your name
strcpy(owner_info->email, "Your Email");       // Replace "Your Email" with your email
strcpy(owner_info->phone, "Your Phone Number"); // Replace "Your Phone Number" with your phone number
```
