// NativeProjectRunner/Android/app/src/main/java/io/canccode/nativeprojectrunner/NativeBridge.kt
package io.canccode.nativeprojectrunner

import android.content.ContentResolver
import android.net.Uri
import java.io.FileDescriptor
import java.io.FileInputStream
import java.io.FileOutputStream

object NativeBridge {

    init {
        System.loadLibrary("nativebridge")
    }

    // Load a project folder (via SAF URI)
    external fun loadProject(resolver: ContentResolver, projectUri: Uri): Boolean

    // Run a module inside the loaded project
    external fun runProjectModule(projectUri: Uri, moduleName: String)
}