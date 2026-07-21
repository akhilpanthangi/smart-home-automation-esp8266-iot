# Uploading This Project to GitHub

## Recommended repository settings

- **Repository name:** `smart-home-automation-esp8266-iot`
- **Description:** `Voice- and app-controlled home automation using NodeMCU ESP8266, Arduino IoT Cloud, Google Home and a four-channel relay.`
- **Visibility:** Public
- **Initialize with README:** No — this project already includes one
- **Add .gitignore:** None — this project already includes one
- **Choose a license:** None — this project already includes the MIT License

## Upload using the GitHub website

1. Sign in to GitHub.
2. Select the **+** menu in the upper-right corner and choose
   **New repository**.
3. Enter the repository name and description shown above.
4. Select **Public** and leave the initialization options unchecked.
5. Select **Create repository**.
6. On the empty repository page, choose **uploading an existing file**.
   If files are already present, use **Add file → Upload files** instead.
7. Open the extracted project folder on your computer and drag all of its
   contents into the upload area. Upload the contents, not the ZIP file alone.
8. Confirm that `README.md`, `firmware`, `docs`, `.gitignore`, `LICENSE` and
   `SECURITY.md` are listed.
9. Use this commit message:

   `Initial commit: add ESP8266 smart home automation project`

10. Select **Commit changes**.

## Final safety check

The public repository must contain `arduino_secrets.example.h`, but it must
never contain `arduino_secrets.h`. Search the uploaded code for your Wi-Fi
password and Arduino device secret before sharing the repository link.

## Optional repository topics

Add these topics from the repository's **About** section:

`esp8266`, `nodemcu`, `arduino-iot-cloud`, `google-home`, `home-automation`,
`iot`, `embedded-systems`, `relay-module`, `voice-control`

## Official GitHub instructions

- [Creating a new repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository)
- [Uploading files in the browser](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository)
