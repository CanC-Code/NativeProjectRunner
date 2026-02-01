// NativeProjectRunner/Android/app/src/main/java/io/canccode/nativeprojectrunner/ProjectPicker.kt
package io.canccode.nativeprojectrunner

import android.app.Activity
import androidx.activity.result.ActivityResultLauncher
import android.content.Intent

object ProjectPicker {
    fun launchPickFolder(activity: Activity, launcher: ActivityResultLauncher<Intent>) {
        val intent = Intent(Intent.ACTION_OPEN_DOCUMENT_TREE)
        intent.addFlags(
            Intent.FLAG_GRANT_READ_URI_PERMISSION or
            Intent.FLAG_GRANT_WRITE_URI_PERMISSION or
            Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION
        )
        launcher.launch(intent)
    }
}