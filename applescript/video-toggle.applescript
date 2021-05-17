set crntAppPath to (path to frontmost application as text)

if crntAppPath contains "Google Chrome" then
  tell application crntAppPath
    tell application "System Events"
      keystroke "e" using {command down}
    end tell
  end tell
end if

if crntAppPath contains "zoom.us" then
  tell application crntAppPath
    tell application "System Events"
      keystroke "v" using {shift down, command down}
    end tell
  end tell
end if

if crntAppPath contains "Microsoft Teams" then
  tell application crntAppPath
    tell application "System Events"
      keystroke "o" using {shift down, command down}
    end tell
  end tell
end if

if crntAppPath contains "BlueJeans" then
    tell application crntAppPath
      tell application "System Events"
        keystroke "v"
        delay 1
      end tell
    end tell
  end if