on getMicrophoneVolume()
  input volume of (get volume settings)
end getMicrophoneVolume
on disableMicrophone()
  say "muted"
  set volume input volume 0
end disableMicrophone
on enableMicrophone()
  say "unmuted"
  set volume input volume 100
end enableMicrophone

on muteApp()
  set crntAppPath to (path to frontmost application as text)
  if crntAppPath contains "Google Chrome" then
    tell application crntAppPath
      tell application "System Events"
        keystroke "d" using {command down}
      end tell
    end tell
  end if
  
  if crntAppPath contains "zoom.us" then
    tell application crntAppPath
      tell application "System Events"
        keystroke "a" using {shift down, command down}
        delay 1
      end tell
    end tell
  end if
  
  if crntAppPath contains "Microsoft Teams" then
    tell application crntAppPath
      tell application "System Events"
        keystroke "m" using {shift down, command down}
        delay 1
      end tell
    end tell
  end if
  
  if crntAppPath contains "BlueJeans" then
    tell application crntAppPath
      tell application "System Events"
        keystroke "m"
        delay 1
      end tell
    end tell
  end if
end muteApp

if getMicrophoneVolume() is greater than 0 then
  muteApp()
  disableMicrophone()
else
  enableMicrophone()
  muteApp()
end if