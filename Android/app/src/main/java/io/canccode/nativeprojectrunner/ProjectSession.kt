// NativeProjectRunner/Android/app/src/main/java/io/canccode/nativeprojectrunner/ProjectSession.kt
package io.canccode.nativeprojectrunner

import android.content.Context
import android.net.Uri
import kotlinx.coroutines.*

class ProjectSession(private val context: Context) {

    private var projectUri: Uri? = null
    var statusListener: ((String) -> Unit)? = null

    fun loadProject(uri: Uri) {
        projectUri = uri
        statusListener?.invoke("Loading project...")
        CoroutineScope(Dispatchers.IO).launch {
            val result = NativeBridge.loadProject(context.contentResolver, uri)
            withContext(Dispatchers.Main) {
                statusListener?.invoke(
                    if (result) "Project loaded successfully"
                    else "Failed to load project"
                )
            }
        }
    }

    fun runModule(moduleName: String) {
        projectUri?.let { uri ->
            NativeBridge.runProjectModule(uri, moduleName)
        }
    }
}