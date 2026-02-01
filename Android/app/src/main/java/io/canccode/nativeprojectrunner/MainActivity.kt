// NativeProjectRunner/Android/app/src/main/java/io/canccode/nativeprojectrunner/MainActivity.kt
package io.canccode.nativeprojectrunner

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {

    private lateinit var projectSession: ProjectSession

    private val pickFolderLauncher = registerForActivityResult(
        ActivityResultContracts.OpenDocumentTree()
    ) { uri ->
        if (uri != null) {
            contentResolver.takePersistableUriPermission(
                uri, Intent.FLAG_GRANT_READ_URI_PERMISSION or Intent.FLAG_GRANT_WRITE_URI_PERMISSION
            )
            projectSession.loadProject(uri)
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        projectSession = ProjectSession(this)

        val pickButton: Button = findViewById(R.id.pickProjectButton)
        pickButton.setOnClickListener {
            ProjectPicker.launchPickFolder(this, pickFolderLauncher)
        }

        val statusText: TextView = findViewById(R.id.projectStatus)
        projectSession.statusListener = { status ->
            statusText.text = status
        }
    }
}