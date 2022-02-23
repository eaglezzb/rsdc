tell application "System Events"
	set isRunning to �
		(count of (every process whose name is "GrowlHelperApp")) > 0
end tell

if isRunning then
	
	tell application "GrowlHelperApp"
		-- Make a list of all the notification types 
		-- that this script will ever send:
		set the allNotificationsList to �
			{"Uniboard Update Install"}
		
		set the enabledNotificationsList to �
			{"Uniboard Update Install"}
		
		register as application �
			"Uniboard" all notifications allNotificationsList �
			default notifications enabledNotificationsList �
			icon of application "Uniboard"
		
		notify with name �
			"Uniboard Update Install" title �
			"Uniboard" description �
			"Uniboard is installing a new version." application name "Uniboard"
		
	end tell
end if