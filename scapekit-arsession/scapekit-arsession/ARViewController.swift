//
//  ViewController.swift
//  pixscape-ios
//
//  Created by bils on 01/12/2018.
//  Copyright © 2018 Scape Technologies. All rights reserved.
//

import UIKit
import ScapeKit

final class ARViewController: UIViewController {

    override var preferredStatusBarStyle : UIStatusBarStyle {
        return .lightContent
    }
    
    lazy var arView: SCKArView = {
        return SCKArView()
    }()
    
    lazy var scapeButton: UIButton = {
        let button = UIButton(frame: CGRect(x: self.view.bounds.width/2 - 50,
                                            y: self.view.bounds.height - 50,
                                            width: 100,
                                            height: 50))
        button.backgroundColor = .green
        button.setTitle("Localize", for: .normal)
        button.addTarget(self, action: #selector(localizeWithSensorsAndVisionEngine), for: .touchUpInside)
        return button
    }()
    
    private var arSession: SCKArSession?
    private var scapeSession: SCKScapeSession?
    private var scapeClient: SCKScapeClient
    
    init(scapeClient: SCKScapeClient) {
        self.scapeClient = scapeClient
        
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(didBecomeActive),
                                               name: NSNotification.Name(rawValue: UIApplication.didBecomeActiveNotification.rawValue),
                                               object: nil)
        
        self.view.addSubview(arView)
        self.view.addSubview(scapeButton)
        
        setupAr()
        setupScape()
    }
    
    override func viewWillLayoutSubviews() {
        super.viewWillLayoutSubviews()
        
        arView.frame = view.bounds
    }
    
    func setupAr() {
        arSession = scapeClient.arSession?.withArView(view: arView)
        arSession?.setDebugMode(false)
        arSession?.resetTracking()
    }
    
    func setupScape() {
        scapeSession = scapeClient.scapeSession
    }
    
    @objc func didBecomeActive() {
        arSession?.resetTracking()
    }
    
    /**
     * Get a GeoPose using raw sensors only
     */
    @objc func localizeWithRawSensors(sender: UIButton!) {
        scapeSession?.getCurrentGeoPose(usageType: .rawSensors,
                                        geoPoseEstimated: { [weak self] details in
                                            guard let `self` = self else {
                                                return
                                            }
                                            self.onGeoPoseEstimated(details: details)
                                            
            },
                                        sessionError: { [weak self] details in
                                            guard let `self` = self else {
                                                return
                                            }
                                            self.onScapeSessionError(details: details)
        })
    }

    
    /**
     * Get a GeoPose using raw sensors and Scape Vision Engine
     */
    @objc func localizeWithSensorsAndVisionEngine(sender: UIButton!) {
        scapeSession?.getCurrentGeoPose(usageType: .rawSensorsAndScapeVisionEngine,
                                        geoPoseEstimated: { [weak self] details in
                                            guard let `self` = self else {
                                                return
                                            }
                                            self.onGeoPoseEstimated(details: details)
                                            
        },
                                        sessionError: { [weak self] details in
                                            guard let `self` = self else {
                                                return
                                            }
                                            self.onScapeSessionError(details: details)
        })
    }
}

private extension ARViewController {
    func onScapeSessionStarted(details: SCKScapeSessionDetails) {
        
    }
    
    func onScapeSessionClosed(details: SCKScapeSessionDetails) {
        
    }
    
    func onScapeSessionError(details: SCKScapeSessionDetails) {
        print("Could not retrieve scape coordinates: \(details.errorMessage)")
        
    }
    
    func onGeoPoseEstimated(details: SCKScapeSessionDetails) {
        let gpsCoordinates = "\(details.geoPose.gpsCoordinates.latitude) \(details.geoPose.gpsCoordinates.longitude) "
        print("Retrieving final GpsCoordinates: \(gpsCoordinates)")

        // check if we got a successful result from Scape Vision Engine as we could have only got
        // gps coordinates coming back from the raw sensors
        if(details.currentState == .scapeLocalizationSuccess) {
            let scapeCoordinates = "\(details.geoPose.scapeCoordinates?.latitude ?? 0.0) \(details.geoPose.scapeCoordinates?.longitude ?? 0.0) \(details.geoPose.scapeRawHeightEstimate ?? 0.0) "
            print("Retrieving final ScapeCoordinates and height estimate: \(scapeCoordinates)")
        }
    }
}

