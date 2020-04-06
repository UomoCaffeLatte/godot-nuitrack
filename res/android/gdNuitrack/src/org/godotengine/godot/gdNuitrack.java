package org.godotengine.godot;

import android.app.Activity;
import android.content.Intent;
import android.content.Context;
import com.godot.game.R;
import android.os.Bundle;
import android.os.Looper;
import com.tdv.nuitrack.sdk.Nuitrack;
import javax.microedition.khronos.opengles.GL10;
import android.util.Log;

public class gdNuitrack extends Godot.SingletonBase {
    protected Activity appActivity;
    protected Context appContext;
    private Godot activity = null;
    private int instanceId = 0;

    public String myFunction(String p_str) {

        // activity.runOnUiThread(new Runnable()
		// {
        //     @Override
        //     public void run() {
        //         Nuitrack.init(appContext, new Nuitrack.NuitrackCallback() {
        //             public void onInitSuccess(Context context) {
        //                 Log.d("Nuitrack","Sucesss ---------------------------------------------------------------------");
        //             }
        //             public void onInitFailure(int errorId) {
        //                 Log.d("NUITRACK","Failure ---------------------------------------------------------------------");
        //             }
        //         });
             
        //     }
        // });

        return  "hello" + p_str;
    }

    public void getInstanceId(int pInstanceId) {
        // You will need to call this method from Godot and pass in the get_instance_id().
        instanceId = pInstanceId;
    }

    static public Godot.SingletonBase initialize(Activity p_activity) {
        return new gdNuitrack(p_activity);
    }

    public gdNuitrack(Activity p_activity) {
        // Register class name and functions to bind.
        registerClass("gdNuitrack", new String[]
            {
                "myFunction",
                "getInstanceId"
            });
        this.appActivity = p_activity;
        this.appContext = appActivity.getApplicationContext();
        // You might want to try initializing your singleton here, but android
        // threads are weird and this runs in another thread, so to interact with Godot you usually have to do.
        this.activity = (Godot)p_activity;
        // this.activity.runOnUiThread(new Runnable() {
        //     public void run() {
        //         Nuitrack.init(appContext, new Nuitrack.NuitrackCallback() {
        //             public void onInitSuccess(Context context) {
        //                 Log.d("Nuitrack","Sucesss ---------------------------------------------------------------------");
        //             }
        //             public void onInitFailure(int errorId) {
        //                 Log.d("NUITRACK","Failure ---------------------------------------------------------------------");
        //             }
        //         });
        //     }
        // });
    }

    // Forwarded callbacks you can reimplement, as SDKs often need them.

    protected void onMainActivityResult(int requestCode, int resultCode, Intent data) {}
    protected void onMainRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {}

    protected void onMainPause() {}
    protected void onMainResume() {}
    protected void onMainDestroy() {}
    protected void onGLDrawFrame(GL10 gl) {}
    protected void onGLSurfaceChanged(GL10 gl, int width, int height) {} // Singletons will always miss first 'onGLSurfaceChanged' call.
}
