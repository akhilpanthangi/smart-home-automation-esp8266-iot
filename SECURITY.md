# Security Policy

## Protecting credentials

This project requires Wi-Fi and Arduino IoT Cloud credentials. Real credentials
must be stored only in:

`firmware/smart_home_automation/arduino_secrets.h`

That filename is excluded by `.gitignore`. Before every push, run `git status`
and confirm that `arduino_secrets.h` is not listed as a tracked file.

## If a secret is exposed

1. Regenerate or replace the Arduino IoT Cloud device secret immediately.
2. Change the exposed Wi-Fi password.
3. Update the private local `arduino_secrets.h` file.
4. Upload the sketch again so the NodeMCU uses the new credentials.

Deleting a secret in a later commit is not sufficient because the original
value can remain in Git history. Always rotate an exposed credential.

## Electrical safety

The relay contacts may switch dangerous mains voltage. Keep mains wiring
isolated from the NodeMCU and other low-voltage wiring. Use correctly rated
relays, protection, insulation and an enclosed installation. Mains wiring
should be performed or inspected by a qualified electrician.
