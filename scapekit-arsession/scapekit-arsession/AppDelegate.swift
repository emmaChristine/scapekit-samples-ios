//
//  AppDelegate.swift
//  pixscape-ios
//
//  Created by bils on 01/12/2018.
//  Copyright © 2018 Scape Technologies. All rights reserved.
//

import UIKit
import ScapeKit

fileprivate func valueForKey(_ key: String) -> String {
    let filePath = Bundle.main.path(forResource: "ScapeKitApiKeys", ofType: "plist")
    let plist = NSDictionary(contentsOfFile:filePath!)
    let value = plist?.object(forKey: key) as! String
    return value
}

@UIApplicationMain
final class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    lazy var scapeClient: SCKScapeClient = {
        return SCKScape.scapeClientBuilder
            .withDebugSupport(true)
            .withApiKey(valueForKey("ScapeKitApiKey"))
            .withArSupport(true)
            .build()
    }()
    
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        UIApplication.shared.statusBarStyle = .lightContent
        
        scapeClient.scapeClientObserver = self
        scapeClient.start()
        
        self.window = UIWindow(frame: UIScreen.main.bounds)
        
        let navController = UINavigationController(rootViewController: ARViewController(scapeClient: scapeClient))
        navController.navigationBar.setBackgroundImage(UIImage(), for: .default)
        navController.navigationBar.shadowImage = UIImage()
        navController.navigationBar.isTranslucent = true
        
        self.window?.rootViewController = navController
        self.window?.makeKeyAndVisible()
        
        return true
    }
    
    func applicationWillResignActive(_ application: UIApplication) {
        if(scapeClient.isStarted) {
            scapeClient.stop()
        }
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        if(scapeClient.isStarted) {
            scapeClient.stop()
        }
    }
    
    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
        if(!scapeClient.isStarted) {
            scapeClient.start()
        }
    }
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
        scapeClient.terminate()
    }
}

extension AppDelegate: SCKScapeClientObserver {
    func onClientStarted(_ scapeClient: SCKScapeClient) {
        
    }
    
    func onClientStopped(_ scapeClient: SCKScapeClient) {
        
    }
    
    func onClientFailed(_ scapeClient: SCKScapeClient, errorMessage: String) {
        
    }
}

